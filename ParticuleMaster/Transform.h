#pragma once

#include "Utils.h"

class Transform
{
public:
	Vec3 m_position;
	Vec3 m_rotation;
	Vec3 m_scale;

	Transform() : m_position(0.0f, 0.0f, 0.0f), m_rotation(0.0f, 0.0f, 0.0f), m_scale(1.0f, 1.0f, 1.0f) {}
	~Transform() {}
};