//
// Created by Federico François on 31/05/21.
//

#include "Character.hpp"

Character::Character(const std::string &name): name(name), ap(40), weapon(nullptr){}

Character::~Character() {
	delete weapon;
}

Character::Character(const Character &character) {
	name = character.name;
	ap = character.ap;
	weapon = character.weapon;
}

Character& Character::operator=(const Character &character) {
	name = character.name;
	ap = character.ap;
	weapon = character.weapon;

	return *this;
}

void Character::recoverAP() {
	if (ap + 10 > 40)
	{
		ap = 40;
		return;
	}
	ap += 10;
}

void Character::attack(Enemy* enemy) {
	if (ap < weapon->getAPCost() || !weapon)
		return;
	std::cout << name << " attacks " << enemy->getType() << " with a " + weapon->getName() << std::endl;
	weapon->attack();
	ap -= weapon->getAPCost();
	enemy->takeDamage(weapon->getDamage());
	if (enemy->getHP() < 1)
		delete enemy;

}

const AWeapon *Character::getWeapon() const {
	return weapon;
}

void Character::equip(AWeapon *aWeapon) {
	weapon = aWeapon;
}

const std::string Character::getName() const {
	return name;
}

int Character::getAP() const{
	return ap;
}

std::ostream&	operator<<(std::ostream& out, const Character& character) {
	const AWeapon *weapon = character.getWeapon();
	out << character.getName() << " has " << character.getAP() << " AP and ";
	if (!weapon)
		out << "is unarmed" << std::endl;
	else
		out << "wields a " + weapon->getName() << std::endl;
	weapon = nullptr;
	return out;
}