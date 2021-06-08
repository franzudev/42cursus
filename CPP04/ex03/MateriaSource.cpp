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
	unsigned int i;

	i = 0;
	if (inventorySize >= 4 || aMateria == nullptr)
		return;
	while (i < inventorySize)
	{
		if (!inventory[inventorySize])
		{
			inventory[i] = aMateria;
			return;
		}
		i++;
	}
	inventory[inventorySize++] = aMateria;
}

AMateria * MateriaSource::createMateria(const std::string &type) {
	for (unsigned int i = inventorySize - 1; i >= 0; i--)
		if (inventory[i] && inventory[i]->getType() == type)
			return inventory[i];
	return 0;
}
