//
// Created by Federico François on 21/05/21.
//

#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	std::string _name;
	const Weapon& _weapon;
public:
	HumanA(std::string name, const Weapon& weapon);
	~HumanA();
	void	attack(void) const;
};

#endif //CPP_HUMANA_HPP
