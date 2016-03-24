#include "GameObject.h"

GameObject::GameObject(std::string name)
{
	// TODO: Initialiser comme il faut
}

void GameObject::AddComponent(Component* component)
{
	// TODO: Ajoute un composant au vector
}

void GameObject::Update()
{
	for each (auto component in m_components)
	{
		component->Update();
	}
}

GameObject::~GameObject()
{
	// TODO: détruire ce qu'il faut
}
