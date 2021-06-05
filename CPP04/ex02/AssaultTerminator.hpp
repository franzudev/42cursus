//
// Created by Federico François on 02/06/21.
//

#ifndef CPP04_ASSAULTTERMINATOR_HPP
#define CPP04_ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator: public ISpaceMarine {
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator& assaultTerminator);
	~AssaultTerminator();
	AssaultTerminator& operator=(const AssaultTerminator& assaultTerminator);
	ISpaceMarine * clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};
#endif //CPP04_ASSAULTTERMINATOR_HPP
