//
// Created by Federico François on 03/06/21.
//

#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
	Ice();
	~Ice();
	Ice(const Ice& ice);
	Ice& operator=(const Ice& ice);
	AMateria *clone() const;
};

#endif //CPP04_ICE_HPP
