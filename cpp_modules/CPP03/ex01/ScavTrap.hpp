//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_SCAVTRAP_HPP
#define CPP03_SCAVTRAP_HPP

#include <iostream>

class ScavTrap {
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	maxHitPoints;
	unsigned int	energyPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	level;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	armorDamageReduction;
public:
	ScavTrap();
	ScavTrap(std::string const &_name);
	~ScavTrap();
	ScavTrap(const ScavTrap& scavTrap);
	ScavTrap& operator=(ScavTrap const &scavTrap);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(void);
};

#endif //CPP03_SCAVTRAP_HPP
