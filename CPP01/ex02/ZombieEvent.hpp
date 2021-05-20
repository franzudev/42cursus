//
// Created by Federico François on 20/05/21.
//

#ifndef CPP_ZOMBIEEVENT_HPP
#define CPP_ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>

class ZombieEvent {
	std::string _type;
public:
	ZombieEvent();
	void		setZombieType(std::string type);
	Zombie*		newZombie(std::string name);
	std::string	randomName();
	void		randomChump(void);
};

#endif //CPP_ZOMBIEEVENT_HPP
