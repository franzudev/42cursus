//
// Created by Federico François on 20/05/21.
//

#include "Zombie.hpp"

std::string randomAnnouncement[3] = {
		"Braiiiiiiiiinnnnssssss...",
		"Aaaaah Aaaaaaaaaah Aaaaaah...",
		"I waaant youuur heaaaaaarth..."
};

Zombie::Zombie() {}

Zombie::Zombie(std::string type, std::string name) {
	_type = type;
	_name = name;
}

void Zombie::announce() {
	std::cout << "<" + _name + " (" + _type + ")> " + randomAnnouncement[rand() % 2] << std::endl;
}
