//
// Created by Federico François on 21/05/21.
//

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

void
HumanB::attack() const {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void
HumanB::setWeapon(const Weapon& weapon) {
	_weapon = &weapon;
}
