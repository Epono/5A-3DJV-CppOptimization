#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

#include "ThreadManager.h"

//Multithreading
//Boss Working

int threadAliveCounter = 0;
int maxThread = 4;
std::vector<std::thread> listOfThread;




//Particles

#include "Particle.h"


#define _256k 262144
#define _64k 65536

int threadcounter = 0;

//ThreadMAX 4

//Memory Pools

//Game Object



//Cache

//SSE

//Spatialisation


void CreateParticle(int _threadNumber, int _numberOfParticles)
{
	int numberOfParticles = _numberOfParticles;

	for (int i = 0; i < numberOfParticles; ++i)
	{
		//std::cout << "Spawn particle number : " << i << std::endl;
	}
	
	std::cout << "Thread " << _threadNumber << " finished\n";
}

/*
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
*/

void main()
{
	
	ThreadManager *  myManager = new ThreadManager();
	//myManager->ThreadUpdate();
	//std::thread tr(CreateParticle, 0, _256k);
	


	





	bool isEnd = false;
	/*while (isEnd)
	{


	std::thread tr0(CreateParticle, 0, _64k);
	std::thread tr1(CreateParticle, 1, _64k);
	std::thread tr2(CreateParticle, 2, _64k);
	std::thread tr3(CreateParticle, 3, _64k);

	tr0.join();
	tr1.join();
	tr2.join();
	tr3.join();


	}*/

	

	std::cout << "Appuyez sur une touche pour fermer la fenetre\n";
	getchar();
}