//
// Created by Federico François on 31/05/21.
//

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21) {
	setName("Plasma Rifle");
	setAPCost(5);
	setDamage(21);
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &plasmaRifle): AWeapon(plasmaRifle) {
	setName(plasmaRifle.name);
	setAPCost(plasmaRifle.apCost);
	setDamage(plasmaRifle.damage);
}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &plasmaRifle) {
	AWeapon::operator=(plasmaRifle);
	setName(plasmaRifle.name);
	setAPCost(plasmaRifle.apCost);
	setDamage(plasmaRifle.damage);

	return *this;
}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}