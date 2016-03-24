#pragma once

class GameObject;

class Component
{
protected:
	GameObject* m_gameObject;

public:
	Component(GameObject* gameObject) 
		: m_gameObject(gameObject) {}
	~Component() {}

	virtual void Update() = 0;
};