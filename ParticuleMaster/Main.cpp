#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

#include "ThreadManager.h"
#include "Particle.h"

#define _256k 262144
#define _64k   65536

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
	ThreadManager* myManager = new ThreadManager();
	Allocator::create(sizeof(Particle) * _256k);

	while(false)
	{
		// Game Loop
		// TODO
		if(true)
		{
			// Update (60 times per second)
			for each (GameObject* gameObject in gameObjects)
			{
				// TODO: envoyer 1/4 à chaque thread
				gameObject->Update();
			}
		}

		// Render (as fast as possible)
		// TODO
	}

	std::cout << "Appuyez sur une touche pour fermer la fenetre\n";
	getchar();
}