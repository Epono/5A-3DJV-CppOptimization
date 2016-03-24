#pragma once

#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"

class GameObject
{
private:
	std::string m_name;
	Transform m_transform;
	std::vector<Component*> m_components;

public:
	GameObject(std::string name);
	void AddComponent(Component* component);
	void Update();
	~GameObject();
};