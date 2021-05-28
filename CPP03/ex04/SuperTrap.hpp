//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_SUPERTRAP_HPP
#define CPP03_SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap {
	SuperTrap();
public:
	SuperTrap(std::string const &_name);
	virtual ~SuperTrap();
	SuperTrap(const SuperTrap& SuperTrap);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
};

#endif //CPP03_SUPERTRAP_HPP
