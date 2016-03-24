#include "GameObject.h"

void GameObject::AddComponent(Component* component)
{
	m_components.emplace_back(component);
}

void GameObject::Update()
{
	for(auto component : m_components)
		component->Update();
}