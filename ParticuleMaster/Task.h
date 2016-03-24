#pragma once
#include <string>

class Task
{
	public :
	std::string m_name;

	Task(std::string name) 
	{
		m_name = name;
	}

	~Task() 
	{
	}
	
};