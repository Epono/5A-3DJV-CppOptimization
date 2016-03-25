#pragma once

#include "Component.h"

class MeshComponent : public Component
{
public:
	MeshComponent(GameObject* gameObject) : Component::Component(gameObject) {}
	~MeshComponent() {}

	void Update();
	ComponentType getComponentType() { return ComponentType::MeshComponent; };
};