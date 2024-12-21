//
// Created by Federico Francois on 5/28/21.
//

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(const std::string &_name): ClapTrap(_name), FragTrap(_name), NinjaTrap(_name) {
	name = _name;
	hitPoints = FragTrap::hitPoints;
	maxHitPoints = FragTrap::maxHitPoints;
	energyPoints = NinjaTrap::energyPoints;
	maxEnergyPoints = NinjaTrap::maxEnergyPoints;
	level = 1;
	meleeAttackDamage = NinjaTrap::meleeAttackDamage;
	rangedAttackDamage = FragTrap::rangedAttackDamage;
	armorDamageReduction = FragTrap::armorDamageReduction;
	std::cout << "<SP4R-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &superTrap): FragTrap(superTrap.name), NinjaTrap(superTrap.name) {
	*this = superTrap;
	std::cout << "<SP4R-TP> " + name + " engine start... ROARRRRRR!!!" << std::endl;
}

SuperTrap::~SuperTrap() {
	std::cout << "<SP4R-TP> " + name + " slowly dying......." << std::endl;
}

void SuperTrap::meleeAttack(const std::string &target) {
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(const std::string &target) {
	FragTrap::rangedAttack(target);
}
