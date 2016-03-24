#include <cassert>

#include "Allocateur.h"

struct FreeBlock * Allocator::m_pFreeBlocks = nullptr;
void * Allocator::m_pStart = nullptr;
size_t Allocator::m_Size = 0;
size_t Allocator::m_MemoryUsed = 0;
size_t Allocator::m_AllocationsDone = 0;

void Allocator::create(size_t i_Size)
{
	m_pStart = malloc(i_Size);
	m_pFreeBlocks = reinterpret_cast<FreeBlock *>(m_pStart);
	m_AllocationsDone = 0;
	m_MemoryUsed = 0;
	assert(i_Size > sizeof(FreeBlock));
	m_pFreeBlocks->size = i_Size;
	m_pFreeBlocks->next = nullptr;
}

void Allocator::destroy()
{
	if (m_pStart != nullptr)
	{
		assert(m_AllocationsDone == 0 && m_MemoryUsed == 0);
		free(m_pStart);
	}
}

Allocator::Allocator(void * i_pStart, size_t i_Size)
{
	m_pStart = i_pStart;
	m_pFreeBlocks = reinterpret_cast<FreeBlock *>(i_pStart);
	m_AllocationsDone = 0;
	m_MemoryUsed = 0;
	assert(i_Size > sizeof(FreeBlock));
	m_pFreeBlocks->size = i_Size;
	m_pFreeBlocks->next = nullptr;
}

Allocator::~Allocator()
{}

void * Allocator::allocate(size_t i_Size, uint8_t i_Alignment)
{
	assert(i_Size != 0 && i_Alignment != 0);
	FreeBlock* previousFreeBlock = nullptr;
	FreeBlock* freeBlock = Allocator::m_pFreeBlocks;
	while (freeBlock != nullptr)
	{
		uint8_t adjustment = alignForwardAdjustmentWithHeader(freeBlock, i_Alignment);
		size_t totalSize = i_Size + adjustment;
		if (freeBlock->size < totalSize)
		{
			previousFreeBlock = freeBlock;
			freeBlock = freeBlock->next;
			continue;
		}
		if (freeBlock->size - totalSize <= sizeof(Header))
		{
			totalSize = freeBlock->size;
			if (previousFreeBlock != nullptr)
				previousFreeBlock->next = freeBlock->next;
			else
				m_pFreeBlocks = freeBlock->next;
		}
		else
		{
			FreeBlock* nextBlock = reinterpret_cast<FreeBlock *>(freeBlock) +totalSize;
			nextBlock->size = freeBlock->size - totalSize;
			nextBlock->next = freeBlock->next;
			if (previousFreeBlock != nullptr)
				previousFreeBlock->next = nextBlock;
			else
				m_pFreeBlocks = nextBlock;
		}
		Header * alignedAddress = reinterpret_cast<Header *>(freeBlock) +adjustment;
		Header * header = alignedAddress - sizeof(Header);
		header->size = totalSize;
		header->adjustment = adjustment;
		m_MemoryUsed += totalSize;
		m_AllocationsDone++;
		return reinterpret_cast<void *>(alignedAddress);
	}
	return nullptr;
}

void Allocator::deallocate(void* i_pAddress)
{
	assert(i_pAddress != nullptr);
	Header * header = reinterpret_cast<Header *>(i_pAddress) -sizeof(Header);
	FreeBlock * blockStart = reinterpret_cast<FreeBlock *>(i_pAddress) -header->adjustment;
	size_t blockSize = header->size;
	FreeBlock * blockEnd = blockStart + blockSize;
	FreeBlock * previousFreeBlock = nullptr;
	FreeBlock * freeBlock = m_pFreeBlocks;
	while (freeBlock != nullptr)
	{
		if (freeBlock >= blockEnd)
			break;
		previousFreeBlock = freeBlock;
		freeBlock = freeBlock->next;
	}

	if (previousFreeBlock == nullptr)
	{
		previousFreeBlock = blockStart;
		previousFreeBlock->size = blockSize;
		previousFreeBlock->next = m_pFreeBlocks;
		m_pFreeBlocks = previousFreeBlock;
	}
	else if (previousFreeBlock + previousFreeBlock->size == blockStart)
		previousFreeBlock->size += blockSize;
	else
	{
		FreeBlock* temp = blockStart;
		temp->size = blockSize;
		temp->next = previousFreeBlock->next;
		previousFreeBlock->next = temp;
		previousFreeBlock = temp;
	}
	if (freeBlock != nullptr && freeBlock == blockEnd)
	{
		previousFreeBlock->size += freeBlock->size;
		previousFreeBlock->next = freeBlock->next;
	}
	m_AllocationsDone--;
	m_MemoryUsed -= blockSize;
}

uint8_t Allocator::alignForwardAdjustmentWithHeader(const void* i_Address, uint8_t i_Alignment)
{
	uint8_t adjustment = i_Alignment - (reinterpret_cast<uintptr_t>(i_Address) & static_cast<uintptr_t>(i_Alignment - 1));
	if (adjustment == i_Alignment)
		adjustment = 0;
	uint8_t neededSpace = sizeof(Header);
	if (adjustment < neededSpace)
	{
		neededSpace -= adjustment;
		adjustment += i_Alignment * (neededSpace / i_Alignment);
		if (neededSpace % i_Alignment > 0)
			adjustment += i_Alignment;
	}
	return adjustment;
}