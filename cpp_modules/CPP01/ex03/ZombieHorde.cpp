//
// Created by Federico François on 20/05/21.
//

#include "ZombieHorde.hpp"

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

ZombieHorde::ZombieHorde(int size) {
	_size = size;
	pZombie = new Zombie*[size];
	setZombieType("Horde");
	for (int i = 0; i < size; i++)
		pZombie[i] = newZombie(randomName());
}

ZombieHorde::~ZombieHorde() {
	for (int i = 0; i < _size; i++)
		delete pZombie[i];
	delete pZombie;
}

void ZombieHorde::setZombieType(std::string type) {
	_type = type;
}

std::string	ZombieHorde::randomName() {
	return randomNames[rand() % 9];
}

Zombie	*ZombieHorde::newZombie(std::string name) {
	Zombie *zombie;

	zombie = new Zombie(_type, name);
	return zombie;
}

void	ZombieHorde::announce() {
	for (int i = 0; i < _size; i++)
		pZombie[i]->announce();
}