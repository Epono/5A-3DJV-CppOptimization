#pragma once

#include "GameObject.h"

class Particle : public GameObject
{
private:
	Vec3 velocity;

public:
	Particle(std::string name) : GameObject(name) {}
	void Update();
	~Particle();
};