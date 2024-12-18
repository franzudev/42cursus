//
// Created by Federico François on 21/05/21.
//

#include "HumanA.hpp"

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, const Weapon& weapon): _name(name), _weapon(weapon) {}

void
HumanA::attack() const{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}