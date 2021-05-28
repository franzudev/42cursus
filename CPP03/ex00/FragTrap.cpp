//
// Created by Federico François on 27/05/21.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	name = "NullFrag";
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "<FR4G-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}


FragTrap::FragTrap(std::string const &_name): name(_name) {
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "<FR4G-TP> " + _name + " engine start... ROARRRRRR!!!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "<FR4G-TP> " + name + " slowly dying......." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	name = fragTrap.name + ".clone";
	hitPoints = fragTrap.hitPoints;
	maxHitPoints = fragTrap.maxHitPoints;
	energyPoints = fragTrap.energyPoints;
	maxEnergyPoints = fragTrap.maxEnergyPoints;
	level = fragTrap.level;
	meleeAttackDamage = fragTrap.meleeAttackDamage;
	rangedAttackDamage = fragTrap.rangedAttackDamage;
	armorDamageReduction = fragTrap.armorDamageReduction;
	std::cout << "<FR4G-TP> " + fragTrap.name + ".clone ready to destroy!" << std::endl;
}

void FragTrap::rangedAttack(const std::string &target) {
	std::cout << "<FR4G-TP> " + name + " attacks " + target + " at range, causing "
	<< rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) {
	std::cout << "<FR4G-TP> " + name + " attacks " + target + " in melee!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "<FR4G-TP> " + name + " gets " << amount << " damages!" << std::endl;
	if (energyPoints + armorDamageReduction - amount < 0)
		energyPoints = 0;
	else
		energyPoints = energyPoints + armorDamageReduction - amount;
}

void FragTrap::beRepaired(unsigned int amount) {
	std::cout << "<FR4G-TP> " + name + " gets repaired for " << amount << " energy points!" << std::endl;
	if (energyPoints + amount > maxEnergyPoints)
		energyPoints = maxEnergyPoints;
	else
		energyPoints = energyPoints + amount;
}
