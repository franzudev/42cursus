//
// Created by Federico François on 03/06/21.
//

#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
public:
	Cure();
	~Cure();
	Cure(const Cure& ice);
	Cure& operator=(const Cure& ice);
	AMateria * clone() const;
};

#endif //CPP04_CURE_HPP
