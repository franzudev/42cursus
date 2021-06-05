//
// Created by Federico François on 31/05/21.
//

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion") {
	setHP(80);
	setType("RadScorpion");
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &radScorpion): Enemy(radScorpion) {
	setHP(radScorpion.hp);
	setType(radScorpion.type);
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion &radScorpion) {
	Enemy::operator=(radScorpion);
	setHP(radScorpion.hp);
	setType(radScorpion.type);

	return *this;
}
