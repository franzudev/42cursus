//
// Created by Federico François on 03/06/21.
//

#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	AMateria **inventory;
	unsigned int inventorySize;
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& materiaSource);
	MateriaSource& operator=(const MateriaSource& materiaSource);
	void learnMateria(AMateria* aMateria);
	AMateria *createMateria(std::string const & type);
	unsigned int getSize() const;
};

#endif //CPP04_MATERIASOURCE_HPP
