#pragma once

#include "Component.h"

class RigidBodyComponent : public Component
{
public:
	RigidBodyComponent(GameObject* gameObject) : Component::Component(gameObject) {}
	~RigidBodyComponent() {}

	void Update();
	ComponentType getComponentType() { return ComponentType::RigidBodyComponent; };
};