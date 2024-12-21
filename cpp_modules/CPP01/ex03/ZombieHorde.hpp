//
// Created by Federico François on 20/05/21.
//

#ifndef CPP_ZOMBIEHORDE_HPP
#define CPP_ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <iostream>

class ZombieHorde {
	int			_size;
	std::string _type;
	Zombie 		**pZombie;
public:
	ZombieHorde(int size);
	~ZombieHorde();
	void		setZombieType(std::string type);
	Zombie*		newZombie(std::string name);
	std::string	randomName( void );
	void 		announce( void );
};

#endif //CPP_ZOMBIEHORDE_HPP
