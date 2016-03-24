#include "Particle.h"

void Particle::Update()
{
	m_transform.m_position.x += velocity.x;
	m_transform.m_position.y += velocity.y;
	m_transform.m_position.z += velocity.z;

	if(m_transform.m_position.x > CUBE_RADIUS || m_transform.m_position.x < -CUBE_RADIUS)
		velocity.x = -velocity.x;
	if(m_transform.m_position.y > CUBE_RADIUS || m_transform.m_position.y < -CUBE_RADIUS)
		velocity.y = -velocity.y;
	if(m_transform.m_position.z > CUBE_RADIUS || m_transform.m_position.z < -CUBE_RADIUS)
		velocity.z = -velocity.z;

	GameObject::Update();
}