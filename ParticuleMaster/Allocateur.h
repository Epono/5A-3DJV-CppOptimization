#pragma once

class GameObject;


template<typename T>
class Allocateur
{
public:
	Allocateur();
	~Allocateur();

private:
	union Item
	{
		T* element;
		Item* next;
	};

	Item* currentItem_;
	Item* lastItem_;
	Item* freeItems_;
};

