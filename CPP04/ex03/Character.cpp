//
// Created by Federico François on 03/06/21.
//

#include "Character.hpp"

Character::Character(const std::string& name): name(name), inventory(new AMateria*[4]), inventorySize(0) {}

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
	int a;

	a = -1;
	for (unsigned int i = 0; i < inventorySize; i++) {
		if (!inventory[i])
			a = i;
	}
	if (inventorySize >= 4)
		return ;
	if (a != -1)
		inventory[a] = m;
	else
		inventory[inventorySize++] = m;
}

const std::string & Character::getName() const {
	return name;
}

void Character::unequip(int idx) {
	if (!(idx < (int)inventorySize && idx > -1))
		return;
	inventory[idx] = nullptr;
	inventorySize--;
}
