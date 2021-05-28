//
// Created by Federico François on 27/05/21.
//

#ifndef CPP02_FRAGTRAP_HPP
#define CPP02_FRAGTRAP_HPP

#include <iostream>

class FragTrap {
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
	FragTrap();
	FragTrap(std::string const &_name);
	~FragTrap();
	FragTrap(const FragTrap& fragTrap);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif //CPP02_FRAGTRAP_HPP
