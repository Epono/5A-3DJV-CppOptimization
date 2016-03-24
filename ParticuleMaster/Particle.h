#pragma once

#include "GameObject.h"

class Particle : public GameObject
{
private:
	Vec3 m_velocity;

public:
	Particle() : GameObject()
	{
		m_velocity = Vec3(((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)));
		m_transform.m_position = Vec3(((float) rand() / (RAND_MAX * CUBE_RADIUS)), ((float) rand() / (RAND_MAX * CUBE_RADIUS)), ((float) rand() / (RAND_MAX * CUBE_RADIUS)));
	}
	Particle(std::string name) : GameObject(name)
	{
		m_velocity = Vec3(((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)));
		m_transform.m_position = Vec3(((float) rand() / (RAND_MAX * CUBE_RADIUS)), ((float) rand() / (RAND_MAX * CUBE_RADIUS)), ((float) rand() / (RAND_MAX * CUBE_RADIUS)));
	}
	~Particle() { GameObject::~GameObject(); }

	void Update();
};