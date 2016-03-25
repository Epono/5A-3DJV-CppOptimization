#include "Task.h"

Task::Task(std::string name, TaskToDo _t)
{
	m_name = name;
	t = _t;

}

Task::~Task()
{

}

void Task::Task1()
{
	std::cout << "TASK 1 !" << std::endl;
}

void Task::Task2()
{
	std::cout << "TASK 2 !" << std::endl;
}

void Task::Task3()
{
	std::cout << "TASK 3 !" << std::endl;
}

void Task::Task4()
{
	std::cout << "TASK 4 !" << std::endl;
}

void Task::Task5()
{
	std::cout << "TASK 5 !" << std::endl;
}