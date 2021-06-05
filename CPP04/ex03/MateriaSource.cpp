//
// Created by Federico François on 03/06/21.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): inventory(new AMateria*[4]), inventorySize(0) {}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	inventorySize = materiaSource.getSize();
	inventory = new AMateria*[4];
	if (!materiaSource.inventory)
		return;
	for (unsigned int i = 0; i < materiaSource.getSize(); i++)
		inventory[i] = materiaSource.inventory[i]->clone();
}

MateriaSource::~MateriaSource() {
	for (unsigned int i = 0; i < inventorySize; i++)
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
	if (inventorySize >= 4 || aMateria == nullptr)
		return;
	inventory[inventorySize++] = aMateria;
}

AMateria * MateriaSource::createMateria(const std::string &type) {
	for (unsigned int i = 0; i < inventorySize; i++)
		if (inventory[i]->getType() == type)
			return inventory[i];
	return 0;
}