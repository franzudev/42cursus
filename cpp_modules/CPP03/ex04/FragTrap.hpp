//
// Created by Federico François on 27/05/21.
//

#ifndef CPP02_FRAGTRAP_HPP
#define CPP02_FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string const &_name);
	virtual ~FragTrap();
	FragTrap(const FragTrap& fragTrap);
	FragTrap& operator=(const FragTrap &fragTrap);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif //CPP02_FRAGTRAP_HPP
