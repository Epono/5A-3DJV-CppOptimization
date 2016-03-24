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
	GameObject(std::string name);
	~GameObject();

	void AddComponent(Component* component);
	void Update();
};