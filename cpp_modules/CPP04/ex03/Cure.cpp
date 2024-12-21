//
// Created by Federico François on 03/06/21.
//

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &cure): AMateria("cure") {
	_xp = cure._xp;
}

Cure& Cure::operator=(const Cure &cure) {
	_xp = cure._xp;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}