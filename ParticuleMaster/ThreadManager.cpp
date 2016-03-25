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
		ListOfThreads.emplace_back(std::thread(&ThreadManager::ThreadUpdate, this, i));
	}

	std::cout << "taille du tab thread : " << ListOfThreads.size() << " // " << ListOfThreads.capacity() << std::endl;

	
}

void ThreadManager::ThreadUpdate(int _id)
{
	//Stockage de la tache dans une variable
	//Task actualTask = nullptr;
	//actualTask = new Task("Test");

	

	//queueOfTask.push(*actualTask);
	
	
	while (true)
	{
		//std::unique_lock<std::mutex> mutex(threadMutex);
		threadMutex.lock();
		


		if (!queueOfTask.empty())
		{
			
			Task actualTask = queueOfTask.front();
			
					
			queueOfTask.pop();
			threadMutex.unlock();
			
			//std::unique_lock<std::mutex>unlock(threadMutex);
						
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
				Display(_id);
			}
			

		}
		else
		{
			threadMutex.unlock();
			std::cout << "THREAD "<< _id << " : IM WAITING ! "  << std::endl;
		}

		
	}

}

void ThreadManager::AddTaskToQueue(Task _taskToAdd)
{
	queueOfTask.push(_taskToAdd);
	std::cout << "New Task" << std::endl;
}

void ThreadManager::RemoveTaskToQueue()
{
	queueOfTask.pop();
	std::cout << "Remove Task" << std::endl;
}

void ThreadManager::Display(int _id)
{
	std::cout << "THREAD NUMBER : " << _id  << " : IM IN A TASK !" << std::endl;
}