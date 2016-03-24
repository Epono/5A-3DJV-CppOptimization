#include "GameObject.h"

void GameObject::AddComponent(Component* component)
{
	m_components.emplace_back(component);
}

void GameObject::Update()
{
	for each (auto component in m_components)
	{
		component->Update();
	}
}