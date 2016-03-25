#pragma once
#include <string>
#include <iostream>
#include "Utils.h"

class Task
{
public:
	std::string m_name;
	TaskToDo t;

	Task(std::string name, TaskToDo _t);
	~Task();

	void Task1();
	void Task2();
	void Task3();
	void Task4();
	void Task5();


};