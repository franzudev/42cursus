//
// Created by Federico Francois on 5/28/21.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	name = "NullClap";
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 100;
	meleeAttackDamage = 100;
	rangedAttackDamage = 100;
	armorDamageReduction = 100;
	std::cout << "<CL4P-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}


ClapTrap::ClapTrap(std::string const &_name): name(_name) {
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 100;
	meleeAttackDamage = 100;
	rangedAttackDamage = 100;
	armorDamageReduction = 100;
	std::cout << "<CL4P-TP> " + _name + " engine start... ROARRRRRR!!!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "<CL4P-TP> " + name + " slowly dying......." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	*this = clapTrap;
	name = clapTrap.name + ".clone";
	std::cout << "<CL4P-TP> " + clapTrap.name + ".clone ready to destroy!" << std::endl;
}

void ClapTrap::rangedAttack(const std::string &target) {
	std::cout << "<CL4P-TP> " + name + " attacks " + target + " at range, causing "
			  << rangedAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(const std::string &target) {
	std::cout << "<CL4P-TP> " + name + " attacks " + target + " at range, causing "
			  << meleeAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "<CL4P-TP> " + name + " gets " << amount << " damages!" << std::endl;
	if (energyPoints + armorDamageReduction - amount < 0)
		energyPoints = 0;
	else
		energyPoints = energyPoints + armorDamageReduction - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "<CL4P-TP> " + name + " gets repaired for " << amount << " energy points!" << std::endl;
	if (energyPoints + amount > maxEnergyPoints)
		energyPoints = maxEnergyPoints;
	else
		energyPoints = energyPoints + amount;
}
