#pragma once
class Component
{
public:
	Component();
	virtual void Update() = 0;
	~Component();
};