#pragma once

#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"

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


	GameObject* operator new(){ return Allocateur::allocate(); }
	void AddComponent(Component* component);
	void Update();
};