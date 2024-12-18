//
// Created by Federico François on 31/05/21.
//

#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50) {
	setName("Power Fist");
	setAPCost(8);
	setDamage(50);
}

PowerFist::PowerFist(const PowerFist &powerFist): AWeapon(powerFist) {
	setName(powerFist.name);
	setAPCost(powerFist.apCost);
	setDamage(powerFist.damage);
}

PowerFist::~PowerFist() {}

PowerFist& PowerFist::operator=(const PowerFist &powerFist) {
	AWeapon::operator=(powerFist);
	setName(powerFist.name);
	setAPCost(powerFist.apCost);
	setDamage(powerFist.damage);

	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *\"" << std::endl;
}