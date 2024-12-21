//
// Created by Federico François on 03/06/21.
//

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type): _type(type), _xp(0) {}

AMateria::AMateria(const AMateria &aMateria): _type(aMateria._type), _xp(aMateria._xp) {}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(const AMateria &aMateria) {
	_type = aMateria._type;
	_xp = aMateria._xp;

	return *this;
}

const std::string & AMateria::getType() const {
	return _type;
}

unsigned int AMateria::getXP() const {
	return _xp;
}

void AMateria::use(ICharacter &target) {
	if (getType() == "ice")
		std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
	if (getType() == "cure")
		std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
	_xp += 10;
}