//
// Created by Federico François on 20/05/21.
//

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	Zombie *zombie[20];
	ZombieEvent zombieEvent;

	zombieEvent = ZombieEvent();
	std::cout << "Creating " << 20 << " black and white zombies on the heap..." << std::endl;
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			zombieEvent.setZombieType("blackHeap");
		else
			zombieEvent.setZombieType("whiteHeap");
		zombie[i] = zombieEvent.newZombie(zombieEvent.randomName());
		zombie[i]->announce();
		delete zombie[i];
	}
//	delete zombie[20];
	std::cout << std::endl << "Creating " << 50 << " black and white zombies on the stack..." << std::endl;
	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
			zombieEvent.setZombieType("blackHeap");
		else
			zombieEvent.setZombieType("whiteHeap");
		zombieEvent.randomChump();
	}
	return 0;
}