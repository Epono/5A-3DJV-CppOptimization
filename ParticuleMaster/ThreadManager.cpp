#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
	maxThread = 4;

	
	ListOfThreads.reserve(4);
	for (int i = 0; i < maxThread; ++i)
	{
		ListOfThreads.push_back(std::thread (&ThreadManager::ThreadUpdate,this));
	}

	std::cout << "taille du tab thread : " << ListOfThreads.size() << " // " << ListOfThreads.capacity() << std::endl;
}


ThreadManager::~ThreadManager()
{

}

void ThreadManager::ThreadUpdate()
{
	//Stockage de la tache dans une variable
	Task * actualTask;
	actualTask = new Task("Test");
	queueOfTask.push(*actualTask);
	std::cout << "New Task" << std::endl;

	//while (true)
	//{
		if (!queueOfTask.empty())
		{
			*actualTask = queueOfTask.back();
			queueOfTask.pop();




			//ListOfTask.pop_back();
			//Execute the task
			if (actualTask->m_name == "Test")
			{
				Display();
			}
			else
			{
				std::cout << "IM WAITING !" << std::endl;
			}

		}
		else
		{

		}
	//}

}

void ThreadManager::AddTaskToList(Task _taskToAdd)
{
	ListOfTask.push_back(_taskToAdd);
}

void ThreadManager::Display()
{
	std::cout << "THREAD NUMBER : " <<  " : IM IN A TASK !" << std::endl;
}