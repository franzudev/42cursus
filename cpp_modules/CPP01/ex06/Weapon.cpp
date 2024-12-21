//
// Created by Federico François on 21/05/21.
//

#include "Weapon.hpp"

Weapon::Weapon(): _type("") {}

Weapon::Weapon(std::string const &type): _type(type) {}

Weapon::~Weapon() {}

const std::string&
Weapon::getType() const{
	return _type;
}

void
Weapon::setType(std::string const &type) {
	_type = type;
}