//
// Created by Federico Francois on 5/28/21.
//

#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP

#include <iostream>

enum TrapType {
	FRAG,
	SCAV
};

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	maxHitPoints;
	unsigned int	level;
	unsigned int	energyPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	armorDamageReduction;
private:
	int				type;
public:
	ClapTrap();
	ClapTrap(std::string const &_name, int type);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& clapTrap);
	ClapTrap& operator=(const ClapTrap &clapTrap);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif //CPP03_CLAPTRAP_HPP
