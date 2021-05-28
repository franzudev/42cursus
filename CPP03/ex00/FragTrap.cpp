//
// Created by Federico François on 27/05/21.
//

#include "FragTrap.hpp"

std::string attacks[5] = {
		"10,000,000 Volt Thunderbolt",
		"All-Out Pummeling",
		"G-Max Cannonade",
		"Moongeist Beam",
		"Soul-Stealing 7-Star Strike"
};

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
	*this = fragTrap;
	name = fragTrap.name + ".clone";
	std::cout << "<FR4G-TP> " + fragTrap.name + ".clone ready to destroy!" << std::endl;
}

void FragTrap::rangedAttack(const std::string &target) {
	std::cout << "<FR4G-TP> " + name + " attacks " + target + " at range, causing "
	<< rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(const std::string &target) {
	std::cout << "<FR4G-TP> " + name + " attacks " + target + " at range, causing "
			  << meleeAttackDamage << " points of damage!" << std::endl;
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (energyPoints < 25)
	{
		std::cout << "<FR4G-TP> " + name + " doesn't have enough energy!" << std::endl;
		return;
	}
	std::cout << "<FR4G-TP> " + name + " use " + attacks[rand() % 5] + " on " + target + " causing "
			  << rand() % 50 << " points of damage!" << std::endl;
	energyPoints -= 25;
}
