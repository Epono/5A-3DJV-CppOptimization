#pragma once

#include "GameObject.h"

class Particle : public GameObject
{
private:
	Vec3 velocity;

public:
	Particle(std::string name) : GameObject(name) { velocity = Vec3(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX))); }
	~Particle() { GameObject::~GameObject(); }

	void Update();
};