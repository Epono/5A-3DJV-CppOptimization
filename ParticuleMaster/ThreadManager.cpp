#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
	maxThread = 4;
	ListOfThreads.reserve(4);
	std::cout << "taille du tab thread : " << ListOfThreads.size() << " // " << ListOfThreads.capacity() << std::endl;
}


ThreadManager::~ThreadManager()
{

}



void ThreadManager::ThreadStart()
{
	for (int i = 0; i < maxThread; ++i)
	{
		//ListOfThreads.push_back(std::thread(&ThreadManager::ThreadUpdate, this));
		ListOfThreads.emplace_back(std::thread(&ThreadManager::ThreadUpdate, this));
	}

	std::cout << "taille du tab thread : " << ListOfThreads.size() << " // " << ListOfThreads.capacity() << std::endl;
}

void ThreadManager::ThreadUpdate()
{
	//Stockage de la tache dans une variable
	//Task actualTask = nullptr;
	//actualTask = new Task("Test");

	std::unique_lock<std::mutex>lock(threadMutex);

	//queueOfTask.push(*actualTask);
	

	//while (true)
	//{
		if (!queueOfTask.empty())
		{
			Task actualTask = queueOfTask.front();
			queueOfTask.pop();
			



			//ListOfTask.pop_back();
			//Execute the task
			switch (actualTask.t)
			{
				case TaskToDo::Task1:
				{
					actualTask.Task1();
					break;
				}
				case TaskToDo::Task2:
				{
					actualTask.Task2();
					break;
				}
				case TaskToDo::Task3:
				{
					actualTask.Task3();
					break;
				}
				case TaskToDo::Task4:
				{
					actualTask.Task4();
					break;
				}
				case TaskToDo::Task5:
				{
					actualTask.Task5();
					break;
				}
				default: 
				{
					break;
				}
			}

			if (actualTask.m_name == "Test")
			{
				Display();
			}
			

		}
		else
		{
			std::cout << "IM WAITING !" << std::endl;
		}
	//}

}

void ThreadManager::AddTaskToList(Task _taskToAdd)
{
	queueOfTask.push(_taskToAdd);
	std::cout << "New Task" << std::endl;
}

void ThreadManager::Display()
{
	std::cout << "THREAD NUMBER : " <<  " : IM IN A TASK !" << std::endl;
}