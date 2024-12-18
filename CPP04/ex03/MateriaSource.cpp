//
// Created by Federico François on 03/06/21.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): inventory(new AMateria*[4]), inventorySize(0) {
	inventory[0] = nullptr;
	inventory[1] = nullptr;
	inventory[2] = nullptr;
	inventory[3] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	inventorySize = materiaSource.getSize();
	inventory = new AMateria*[4];
	if (!materiaSource.inventory)
		return;
	for (unsigned int i = 0; i < materiaSource.getSize(); i++)
		inventory[i] = materiaSource.inventory[i]->clone();
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
	delete[] inventory;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &materiaSource) {
	inventorySize = materiaSource.getSize();
	inventory = new AMateria *[4];
	for (unsigned int i = 0; i < materiaSource.getSize(); i++)
		inventory[i] = materiaSource.inventory[i]->clone();
	return *this;
}

unsigned int MateriaSource::getSize() const{
	return inventorySize;
}

void MateriaSource::learnMateria(AMateria *aMateria) {
	if (aMateria == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = aMateria;
			return;
		}
	}
	delete aMateria;
}

AMateria * MateriaSource::createMateria(std::string const &type) {
	for (int i = 3; i >= 0; i--) {
		if (inventory[i]) {
			if (inventory[i]->getType() == type)
				return inventory[i];
		}
	}
	return nullptr;
}
