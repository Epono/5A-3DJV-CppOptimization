#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

#include "ThreadManager.h"
#include "Particle.h"

#define _256k 262144
#define _64k   65536

enum bite
{
	tache1, tache2
};

// Multithreading
// Boss Working
// ThreadMAX 4
// Memory Pools
// Game Object
// Cache
// SSE
// Spatialisation

std::vector<GameObject*> gameObjects;

void main()
{
	ThreadManager*  myManager = new ThreadManager();

	while(true)
	{
		// Game Loop
		// TODO
		if(true)
		{
			// Update (60 times per second)
			for each (GameObject* gameObject in gameObjects)
			{
				gameObject->Update();
			}
		}

		// Render (as fast as possible)
		// TODO
	}

	std::cout << "Appuyez sur une touche pour fermer la fenetre\n";
	getchar();
}