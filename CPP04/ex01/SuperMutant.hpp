//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_SUPERMUTANT_HPP
#define CPP04_SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant: public Enemy {
protected:
	unsigned int	hp;
	std::string		type;
public:
	SuperMutant();
	SuperMutant(const SuperMutant& superMutant);
	virtual ~SuperMutant();
	SuperMutant& operator=(const SuperMutant& superMutant);
	std::string const& getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

#endif //CPP04_SUPERMUTANT_HPP
