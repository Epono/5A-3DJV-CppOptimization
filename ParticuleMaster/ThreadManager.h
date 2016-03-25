#pragma once
#include <thread>
#include <vector>
#include <mutex>
#include <functional>
#include <iostream>
#include <queue>
#include "Task.h"

class ThreadManager
{


	enum ThreadState
	{
		SLEEP,
		AWAKE,
		RUNNING
	};

	

private:
	int maxThread;

public:
	std::mutex threadMutex;
	std::vector<std::thread> ListOfThreads;
	std::vector<Task> ListOfTask;
	std::queue <Task> queueOfTask;

	//TaskToDo t;
	//std::unique_lock<std::mutex> m(threadMutex);


	ThreadManager();
	~ThreadManager();
	void ThreadStart();
	void ThreadUpdate(int _id);
	void AddTaskToQueue(Task _taskToAdd);
	void RemoveTaskToQueue();
	void Display(int _id);


};


/*

//THE BOSS
for (int i = 0; i < maxThread; ++i)
{
//pthread_create(pool_base)
while (true)
{
//getRequest
//putRequestinWorkingQueue
//signal sleeping threads that work is available
}

}
*/



/*
void pool_base() /* All workers
{
bool endAll = false;
char c;


while (!endAll)
{
//wait call from Boss

//dequeue a work request

//switch
// case request X : taskX()
// case request Y : taskY()

switch (c)
{
case '1':
{
//task1;
break;
}
default:
{
break;
}
}
}

}
*/