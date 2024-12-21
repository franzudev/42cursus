//
// Created by Federico François on 02/06/21.
//

#ifndef CPP04_TACTICALMARINE_HPP
#define CPP04_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine: public ISpaceMarine {
public:
	TacticalMarine();
	TacticalMarine(const TacticalMarine& tacticalMarine);
	~TacticalMarine();
	TacticalMarine& operator=(const TacticalMarine& tacticalMarine);
	ISpaceMarine * clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif //CPP04_TACTICALMARINE_HPP
