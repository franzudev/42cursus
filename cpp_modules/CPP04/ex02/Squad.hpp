//
// Created by Federico François on 02/06/21.
//

#ifndef CPP04_SQUAD_HPP
#define CPP04_SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

class Squad: public ISquad {
	int	count;
	ISpaceMarine	**units;
public:
	Squad();
	Squad(const Squad& squad);
	~Squad();
	Squad& operator=(const Squad& squad);
	ISpaceMarine *getUnit(int) const;
	int getCount() const;
	int push(ISpaceMarine *);
};

#endif //CPP04_SQUAD_HPP
