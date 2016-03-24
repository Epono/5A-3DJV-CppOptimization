#pragma once

#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"
#include "Allocateur.h"

class GameObject
{
protected:
	std::string m_name;
	Transform m_transform;
	std::vector<Component*> m_components;

public:
	GameObject() : m_name("go") {}
	GameObject(std::string name) : m_name(name) {}
	~GameObject() 
	{ 
		for(auto component : m_components)
			component->~Component();
	}

	void* operator new(size_t size){ return Allocator::allocate(size); }
	void operator delete(void* p) { Allocator::deallocate(p); }

	void AddComponent(Component* component);
	void Update();
};