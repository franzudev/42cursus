//
// Created by Federico François on 20/05/21.
//

#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string	_type;
	std::string	_name;
public:
	Zombie();
	Zombie(std::string type, std::string name);
	void		announce();
};

#endif //CPP_ZOMBIE_HPP
