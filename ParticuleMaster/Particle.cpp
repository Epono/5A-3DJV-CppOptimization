#include "Particle.h"

void Particle::Update()
{
	m_transform.m_position.x += m_velocity.x;
	m_transform.m_position.y += m_velocity.y;
	m_transform.m_position.z += m_velocity.z;

	if(m_transform.m_position.x > CUBE_RADIUS || m_transform.m_position.x < -CUBE_RADIUS)
		m_velocity.x = -m_velocity.x;
	if(m_transform.m_position.y > CUBE_RADIUS || m_transform.m_position.y < -CUBE_RADIUS)
		m_velocity.y = -m_velocity.y;
	if(m_transform.m_position.z > CUBE_RADIUS || m_transform.m_position.z < -CUBE_RADIUS)
		m_velocity.z = -m_velocity.z;

	GameObject::Update();
}