#pragma once

class GameObject;

enum ComponentType
{
	RigidBodyComponent, MeshComponent, RendererComponent
};

class Component
{
protected:
	GameObject* m_gameObject;

public:
	Component(GameObject* gameObject)
		: m_gameObject(gameObject) {}
	~Component() {}

	virtual void Update() = 0;
	virtual ComponentType getComponentType() const = 0;
};