//
// Created by Federico François on 31/05/21.
//

#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name) {
	setName(name);
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &peon) {
	setName(peon.name);
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon& Peon::operator=(const Peon &peon) {
	setName(peon.name);

	return *this;
}

void Peon::getPolymorphed(void) const {
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}