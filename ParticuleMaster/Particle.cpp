#include "Particle.h"

void Particle::Update()
{
	velocity.x += (((double) rand() / (RAND_MAX)) - 0.5) / 10;
	velocity.y += (((double) rand() / (RAND_MAX)) - 0.5) / 10;
	velocity.z += (((double) rand() / (RAND_MAX)) - 0.5) / 10;

	m_transform.m_position.x += velocity.x;
	m_transform.m_position.y += velocity.y;
	m_transform.m_position.z += velocity.z;

	GameObject::Update();
}