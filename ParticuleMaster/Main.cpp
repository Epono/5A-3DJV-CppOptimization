#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

#include "ThreadManager.h"
#include "Particle.h"

#define _256k 262144
#define _64k 65536

// Multithreading
// Boss Working
// ThreadMAX 4
// Memory Pools
// Game Object
// Cache
// SSE
// Spatialisation

int threadAliveCounter = 0;
int maxThread = 4;
std::vector<std::thread> listOfThread;
int threadcounter = 0;

void CreateParticle(int _threadNumber, int _numberOfParticles)
{
	int numberOfParticles = _numberOfParticles;

	for (int i = 0; i < numberOfParticles; ++i)
	{
		//std::cout << "Spawn particle number : " << i << std::endl;
	}
	
	std::cout << "Thread " << _threadNumber << " finished\n";
}

void main()
{
	ThreadManager *  myManager = new ThreadManager();

	std::cout << "Appuyez sur une touche pour fermer la fenetre\n";
	getchar();
}