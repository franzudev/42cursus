//
// Created by Federico François on 03/06/21.
//

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &ice): AMateria("ice") {
	_xp = ice._xp;
}

Ice& Ice::operator=(const Ice &ice) {
	_xp = ice._xp;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}