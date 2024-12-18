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

ScavTrap::ScavTrap(): ClapTrap() {
	name = "NullScav";
	std::cout << "<SC4V-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &_name): ClapTrap(_name, SCAV) {
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

ScavTrap::ScavTrap(const ScavTrap &scavTrap): ClapTrap(scavTrap) {
	name = scavTrap.name + ".clone";
	hitPoints = scavTrap.hitPoints;
	maxHitPoints = scavTrap.maxHitPoints;
	energyPoints = scavTrap.energyPoints;
	maxEnergyPoints = scavTrap.maxEnergyPoints;
	level = scavTrap.level;
	meleeAttackDamage = scavTrap.meleeAttackDamage;
	rangedAttackDamage = scavTrap.rangedAttackDamage;
	armorDamageReduction = scavTrap.armorDamageReduction;
	std::cout << "<SC4V-TP> " + name + " ready to destroy!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap) {
	ClapTrap::operator=(scavTrap);
	name = scavTrap.name + ".clone";
	hitPoints = scavTrap.hitPoints;
	maxHitPoints = scavTrap.maxHitPoints;
	energyPoints = scavTrap.energyPoints;
	maxEnergyPoints = scavTrap.maxEnergyPoints;
	level = scavTrap.level;
	meleeAttackDamage = scavTrap.meleeAttackDamage;
	rangedAttackDamage = scavTrap.rangedAttackDamage;
	armorDamageReduction = scavTrap.armorDamageReduction;
	std::cout << "<SC4V-TP> " + name + " ready to destroy!" << std::endl;

	return *this;
}

void ScavTrap::challengeNewcomer() {
	std::cout << "<SC4V-TP> " + name + " launch challenge: \"" + challenges[rand() % 5] + "\"" << std::endl;
}
