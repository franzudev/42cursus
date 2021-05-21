//
// Created by Federico François on 21/05/21.
//

#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	std::string _name;
	const Weapon* _weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void) const;
	void	setWeapon(const Weapon& weapon);
};

#endif //CPP_HUMANB_HPP
