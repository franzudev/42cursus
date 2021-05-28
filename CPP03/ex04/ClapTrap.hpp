//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	unsigned int	hitPoints;
	unsigned int	maxHitPoints;
	unsigned int	level;
	unsigned int	energyPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	armorDamageReduction;
public:
	std::string		name;
	ClapTrap();
	ClapTrap(std::string const &_name);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& clapTrap);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif //CPP03_CLAPTRAP_HPP
