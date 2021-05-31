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


ClapTrap::ClapTrap(std::string const &_name, int type): name(_name), type(type){
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
	name = clapTrap.name + ".clone";
	type = clapTrap.type;
	hitPoints = clapTrap.hitPoints;
	maxHitPoints = clapTrap.maxHitPoints;
	energyPoints = clapTrap.energyPoints;
	maxEnergyPoints = clapTrap.maxEnergyPoints;
	level = clapTrap.level;
	meleeAttackDamage = clapTrap.meleeAttackDamage;
	rangedAttackDamage = clapTrap.rangedAttackDamage;
	armorDamageReduction = clapTrap.armorDamageReduction;

	std::cout << "<CL4P-TP> " + name + " ready to destroy!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap) {
	name = clapTrap.name + ".clone";
	type = clapTrap.type;
	hitPoints = clapTrap.hitPoints;
	maxHitPoints = clapTrap.maxHitPoints;
	energyPoints = clapTrap.energyPoints;
	maxEnergyPoints = clapTrap.maxEnergyPoints;
	level = clapTrap.level;
	meleeAttackDamage = clapTrap.meleeAttackDamage;
	rangedAttackDamage = clapTrap.rangedAttackDamage;
	armorDamageReduction = clapTrap.armorDamageReduction;

	std::cout << "<CL4P-TP> " + name + " ready to destroy!" << std::endl;

	return *this;
}

void ClapTrap::rangedAttack(const std::string &target) {
	if (type == FRAG)
		std::cout << "<FR4G-TP> ";
	else if (type == SCAV)
		std::cout << "<SC4V-TP> ";

	std::cout << name + " attacks " + target + " at range, causing "
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
