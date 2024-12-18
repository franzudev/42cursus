//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_NINJATRAP_HPP
#define CPP03_NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap: virtual public ClapTrap {
public:
	NinjaTrap();
	NinjaTrap(std::string const &_name);
	virtual ~NinjaTrap();
	NinjaTrap(const NinjaTrap& ninjaTrap);
	NinjaTrap& operator=(const NinjaTrap& ninjaTrap);
	void	ninjaShoebox(FragTrap& flagTrap);
	void	ninjaShoebox(ClapTrap& clapTrap);
	void	ninjaShoebox(ScavTrap& scavTrap);
	void	ninjaShoebox(NinjaTrap& ninjaTrap);
};

#endif //CPP03_NINJATRAP_HPP
