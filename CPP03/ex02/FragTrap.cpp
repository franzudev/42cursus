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

FragTrap::FragTrap(): ClapTrap() {
	name = "NullFrag";
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "<FR4G-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}


FragTrap::FragTrap(std::string const &_name): ClapTrap(_name, FRAG) {
	level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "<FR4G-TP> " + _name + " engine start... ROARRRRRR!!!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "<FR4G-TP> " + name + " slowly dying......." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap): ClapTrap(fragTrap) {
	name = fragTrap.name + ".clone";
	hitPoints = fragTrap.hitPoints;
	maxHitPoints = fragTrap.maxHitPoints;
	energyPoints = fragTrap.energyPoints;
	maxEnergyPoints = fragTrap.maxEnergyPoints;
	level = fragTrap.level;
	meleeAttackDamage = fragTrap.meleeAttackDamage;
	rangedAttackDamage = fragTrap.rangedAttackDamage;
	armorDamageReduction = fragTrap.armorDamageReduction;
	std::cout << "<FR4G-TP> " + name + " ready to destroy!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap) {
	ClapTrap::operator=(fragTrap);
	name = fragTrap.name + ".clone";
	hitPoints = fragTrap.hitPoints;
	maxHitPoints = fragTrap.maxHitPoints;
	energyPoints = fragTrap.energyPoints;
	maxEnergyPoints = fragTrap.maxEnergyPoints;
	level = fragTrap.level;
	meleeAttackDamage = fragTrap.meleeAttackDamage;
	rangedAttackDamage = fragTrap.rangedAttackDamage;
	armorDamageReduction = fragTrap.armorDamageReduction;
	std::cout << "<FR4G-TP> " + name + " ready to destroy!" << std::endl;

	return *this;
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
