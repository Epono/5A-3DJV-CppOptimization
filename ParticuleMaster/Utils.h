#pragma once

#define CUBE_RADIUS 10

enum TaskToDo
{
	Task1,
	Task2,
	Task3,
	Task4,
	Task5
};


struct Vec3
{
	float x;
	float y;
	float z;

	Vec3() {}
	Vec3(float iX, float iY, float iZ) : x(iX), y(iY), z(iZ) {}
};