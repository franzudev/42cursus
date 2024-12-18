//
// Created by Federico François on 03/06/21.
//

#include "Character.hpp"

Character::Character(const std::string& name): name(name), inventory(new AMateria*[4]), inventorySize(0) {
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}

Character::~Character() {
	delete[] inventory;
}

Character::Character(const Character &character) {
	*this = character;
}

Character & Character::operator=(const Character &character) {
	name = character.name;
	inventory = new AMateria*[4];
	inventorySize = character.inventorySize;
	for (unsigned int i = 0; i < character.inventorySize; i++)
		inventory[i] = character.inventory[i]->clone();
	return *this;
}

void Character::use(int idx, ICharacter &target) {
	if (!(idx < 4 && idx > -1))
		return;
	if (inventory[idx])
		inventory[idx]->use(target);
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			break;
		}
	}
}

const std::string & Character::getName() const {
	return name;
}

void Character::unequip(int idx) {
	if (!(idx < 4 && idx > -1))
		return;
	inventory[idx] = nullptr;
}
