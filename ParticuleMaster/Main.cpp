#include <iostream>
#include <atomic>
#include <thread>
#include <vector>


//Multithreading
//Boss Working

int threadAliveCounter = 0;
int maxThread = 4;
std::vector<std::thread> listOfThread;




void pool_base() /* All workers */
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



//Particles

struct Particle
{
	int posX, posY;
	int ID;
	
	Particle()
	{
		posX = 0;
		posY = 0;
		
	}
};


//ThreadMAX 4

//Memory Pools

//Game Object



//Cache

//SSE

//Spatialisation


void CreateParticle(int _numberOfParticles)
{
	int numberOfParticles = _numberOfParticles;

	for (int i = 0; i < numberOfParticles; ++i)
	{
		std::cout << "Spawn particle number : " << i << std::endl;
	}
	

}


bool CreateThread()
{
	bool isCorrect = false;
	
	std::thread tr0;
	listOfThread.push_back(tr0);


	//TO DO
	//if thread well created return true
	//else return false

	isCorrect = true;

	return isCorrect;
}

void ThreadPoolManager()
{
	if (CreateThread())
	{
		threadAliveCounter++;
	}
	

	std::cout << "Il y a " << threadAliveCounter << " existants ! " << std::endl;

}

void main()
{
	ThreadPoolManager();




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




	bool isEnd = false;
	/*while (isEnd)
	{


	}*/

	

	getchar();


}