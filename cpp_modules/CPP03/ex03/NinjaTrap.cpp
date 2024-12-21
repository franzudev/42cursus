//
// Created by Federico Francois on 5/28/21.
//

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap() {
	name = "NullNinja";
	level = 1;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	meleeAttackDamage = 60;
	rangedAttackDamage = 5;
	armorDamageReduction = 0;
	std::cout << "<NNJ4-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}


NinjaTrap::NinjaTrap(std::string const &_name): ClapTrap(_name) {
	level = 1;
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	meleeAttackDamage = 60;
	rangedAttackDamage = 5;
	armorDamageReduction = 0;
	std::cout << "<NNJ4-TP> " + _name + " engine start... ROARRRRRR!!!" << std::endl;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "<NNJ4-TP> " + name + " slowly dying......." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &ninjaTrap): ClapTrap(ninjaTrap) {
	name = ninjaTrap.name + ".clone";
	hitPoints = ninjaTrap.hitPoints;
	maxHitPoints = ninjaTrap.maxHitPoints;
	energyPoints = ninjaTrap.energyPoints;
	maxEnergyPoints = ninjaTrap.maxEnergyPoints;
	level = ninjaTrap.level;
	meleeAttackDamage = ninjaTrap.meleeAttackDamage;
	rangedAttackDamage = ninjaTrap.rangedAttackDamage;
	armorDamageReduction = ninjaTrap.armorDamageReduction;
	std::cout << "<FR4G-TP> " + name + " ready to destroy!" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &ninjaTrap) {
	ClapTrap::operator=(ninjaTrap);
	name = ninjaTrap.name + ".clone";
	hitPoints = ninjaTrap.hitPoints;
	maxHitPoints = ninjaTrap.maxHitPoints;
	energyPoints = ninjaTrap.energyPoints;
	maxEnergyPoints = ninjaTrap.maxEnergyPoints;
	level = ninjaTrap.level;
	meleeAttackDamage = ninjaTrap.meleeAttackDamage;
	rangedAttackDamage = ninjaTrap.rangedAttackDamage;
	armorDamageReduction = ninjaTrap.armorDamageReduction;
	std::cout << "<FR4G-TP> " + name + " ready to destroy!" << std::endl;

	return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap &clapTrap) {
	std::cout << "<NNJ4-TP> " + name + " use ninjaShoebox to " + clapTrap.name + " and gives him " << 25 << " damages!" << std::endl;
	clapTrap.takeDamage(25);
}

void NinjaTrap::ninjaShoebox(FragTrap &fragTrap) {
	std::cout << "<NNJ4-TP> " + name + " use ninjaShoebox to " + fragTrap.name + " and gives him " << 28 << " damages!" << std::endl;
	fragTrap.takeDamage(28);
}

void NinjaTrap::ninjaShoebox(ScavTrap &scavTrap) {
	std::cout << "<NNJ4-TP> " + name + " use ninjaShoebox to " + scavTrap.name + " and gives him " << 36 << " damages!" << std::endl;
	scavTrap.takeDamage(36);
}

void NinjaTrap::ninjaShoebox(NinjaTrap &ninjaTrap) {
	std::cout << "<NNJ4-TP> " + name + " use ninjaShoebox to " + ninjaTrap.name + " and gives him " << 40 << " damages!" << std::endl;
	ninjaTrap.takeDamage(40);
}
