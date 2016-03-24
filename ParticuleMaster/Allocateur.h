#pragma once

#include <stdint.h>
#include <stdlib.h>

struct Header
{
	size_t size;
	uint8_t adjustment;
};

struct FreeBlock
{
	size_t size;
	FreeBlock* next;
};

class Allocator
{
public:
	~Allocator();
	static void create(size_t i_Size);
	static void destroy();
	static void* allocate(size_t i_Size, uint8_t i_Alignment = 4);
	static void deallocate(void* i_pLocation);
private:
	static FreeBlock * m_pFreeBlocks;
	static void * m_pStart;
	static size_t m_Size;
	static size_t m_MemoryUsed;
	static size_t m_AllocationsDone;
	Allocator(void * i_pStart, size_t i_Size);
	static uint8_t alignForwardAdjustmentWithHeader(const void* i_Address, uint8_t i_Alignment);
};
