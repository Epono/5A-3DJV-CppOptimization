#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

int threadcounter = 0;

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

//Multithreading

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


void main()
{

	bool isEnd = false;
	/*while (isEnd)
	{


	}*/


	std::thread tr0(CreateParticle,100);

	tr0.join();

	//CreateParticle(100);
	threadcounter++;

	getchar();


}