//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_SCAVTRAP_HPP
#define CPP03_SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string const &_name);
	~ScavTrap();
	ScavTrap(const ScavTrap& scavTrap);
	ScavTrap& operator=(const ScavTrap &scavTrap);
	void	challengeNewcomer(void);
};

#endif //CPP03_SCAVTRAP_HPP
