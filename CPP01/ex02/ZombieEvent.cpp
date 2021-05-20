//
// Created by Federico François on 20/05/21.
//

#include "ZombieEvent.hpp"

std::string randomNames[10] = {
		"Tom",
		"Jerry",
		"Alpine",
		"Docker",
		"Kubernetes",
		"Gianni",
		"Pinotto",
		"Tarzan",
		"Sandokan",
		"Conan"
};

ZombieEvent::ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type) {
	_type = type;
}

std::string	ZombieEvent::randomName() {
	return randomNames[rand() % 9];
}

Zombie	*ZombieEvent::newZombie(std::string name) {
	Zombie *zombie;

	zombie = new Zombie(_type, name);
	return zombie;
}

void	ZombieEvent::randomChump() {
	Zombie zombie = Zombie(_type, randomName());

	zombie.announce();
}