#pragma once

#include "Component.h"

class RendererComponent : public Component
{
public:
	RendererComponent(GameObject* gameObject) : Component::Component(gameObject) {}
	~RendererComponent() {}

	void Update();
	ComponentType getComponentType() { return ComponentType::RendererComponent; };
};