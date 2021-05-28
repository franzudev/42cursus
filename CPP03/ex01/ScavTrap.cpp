//
// Created by Federico Francois on 5/28/21.
//

#include "ScavTrap.hpp"

std::string challenges[5] = {
		"Captain Scarlett and Her Pirate's Booty",
		"Mr Torgue's Campaign of Carnage",
		"Tiny Tina's Assault on Dragon Keep",
		"Bounty of Blood",
		"Guns, Love, and Tentacles"
};

ScavTrap::ScavTrap() {
	name = "NullScav";
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "<SC4V-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &_name): name(_name) {
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	level = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;
	std::cout << "<SC4V-TP> " + _name + " engine start... ROARRRRRR!!!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "<SC4V-TP> " + name + " slowly dying......." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	*this = scavTrap;
	name = scavTrap.name + ".clone";
	std::cout << "<SC4V-TP> " + scavTrap.name + ".clone ready to destroy!" << std::endl;
}

void ScavTrap::rangedAttack(const std::string &target) {
	std::cout << "<SC4V-TP> " + name + " attacks " + target + " at range, causing "
			  << rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(const std::string &target) {
	std::cout << "<SC4V-TP> " + name + " attacks " + target + " at range, causing "
			  << meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "<SC4V-TP> " + name + " gets " << amount << " damages!" << std::endl;
	if (energyPoints + armorDamageReduction - amount < 0)
		energyPoints = 0;
	else
		energyPoints = energyPoints + armorDamageReduction - amount;
}

void ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "<SC4V-TP> " + name + " gets repaired for " << amount << " energy points!" << std::endl;
	if (energyPoints + amount > maxEnergyPoints)
		energyPoints = maxEnergyPoints;
	else
		energyPoints = energyPoints + amount;
}

void ScavTrap::challengeNewcomer() {
	std::cout << "<SC4V-TP> " + name + " launch challenge: \"" + challenges[rand() % 5] + "\"" << std::endl;
}
