#pragma once
class Component
{
protected:
	GameObject m_gameObject;

public:
	Component() {}
	~Component() {}

	virtual void Update() = 0;
	void SetGameObject(GameObject* gameObject) { m_gameObject = *gameObject; }
};