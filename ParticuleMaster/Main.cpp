#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <ctime>

#include "ThreadManager.h"
#include "Particle.h"

#define _256k 262144
#define _64k   65536

#define UPDATE_DELAY (1.0/60.0) * 1000.0

// Multithreading
// Boss Working
// ThreadMAX 4
// Memory Pools
// Game Object
// Cache
// SSE
// Spatialisation

std::vector<GameObject*> gameObjects;

void Render()
{
	//std::cout << "Rendering..." << std::endl;
}

void main()
{
	ThreadManager*  myManager = new ThreadManager();
	Task* actualTask = new Task("Test",Task1);
	myManager->AddTaskToList(*actualTask);
	actualTask = new Task("Other", Task2);
	myManager->AddTaskToList(*actualTask);
	actualTask = new Task("Other", Task3);
	myManager->AddTaskToList(*actualTask);
	myManager->ThreadStart();

	std::clock_t timeSinceLastUpdate(0);

	//Allocator::create(sizeof(Particle) * _256k);

	while(true)
	{
		double timeElapsed = (std::clock() - timeSinceLastUpdate);
		// Game Loop
		if(timeElapsed > UPDATE_DELAY)
		{
			// Update (60 times per second)
			std::cout << timeElapsed << " ms - Updating Game Object..." << std::endl;
			for each (GameObject* gameObject in gameObjects)
			{
				gameObject->Update();
			}
			timeSinceLastUpdate = std::clock();
		}

		// Render (as fast as possible)
		Render();
	}

	std::cout << "Appuyez sur une touche pour fermer la fenetre\n";
	getchar();
}