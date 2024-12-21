//
// Created by Federico François on 31/05/21.
//

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant") {
	setHP(170);
	setType("Super Mutant");
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &superMutant): Enemy(superMutant) {
	setHP(superMutant.hp);
	setType(superMutant.type);
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant &superMutant) {
	Enemy::operator=(superMutant);
	setHP(superMutant.hp);
	setType(superMutant.type);

	return *this;
}

void SuperMutant::takeDamage(int damage) {
	if (damage < 1)
		return;
	if (hp - damage + 3 < 0)
	{
		hp = 0;
		return ;
	}
	hp -= damage + 3;
}


