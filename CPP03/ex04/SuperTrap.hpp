//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_SUPERTRAP_HPP
#define CPP03_SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap {
	SuperTrap();
	SuperTrap(std::string const &_name);
	~SuperTrap();
	SuperTrap(const SuperTrap& SuperTrap);
};

#endif //CPP03_SUPERTRAP_HPP
