//
// Created by Federico François on 03/06/21.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;
	unsigned int _xp;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& aMateria);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& aMateria);
	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //CPP04_AMATERIA_HPP
