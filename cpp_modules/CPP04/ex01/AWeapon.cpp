//
// Created by Federico François on 31/05/21.
//

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage): name(name), damage(damage), apCost(apcost) {}

AWeapon::AWeapon(const AWeapon &aWeapon) {
	setName(aWeapon.name);
	setAPCost(aWeapon.apCost);
	setDamage(aWeapon.damage);
}

AWeapon::~AWeapon() {}

AWeapon& AWeapon::operator=(const AWeapon& aWeapon) {
	setName(aWeapon.name);
	setAPCost(aWeapon.apCost);
	setDamage(aWeapon.damage);

	return *this;
}

const std::string& AWeapon::getName() const {
	return name;
}

void AWeapon::setName(std::string str) {
	name = str;
}

int AWeapon::getAPCost() const {
	return apCost;
}

void AWeapon::setAPCost(unsigned int val) {
	apCost = val;
}

int AWeapon::getDamage() const {
	return damage;
}

void AWeapon::setDamage(unsigned int val) {
	damage = val;
}