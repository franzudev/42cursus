//
// Created by Federico François on 31/05/21.
//

#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(std::string name): name(name) {
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim::Victim(const Victim &victim) {
	setName(victim.name);
}

Victim& Victim::operator=(const Victim &victim) {
	setName(victim.name);

	return *this;
}

std::string	Victim::introduce(void) {
	return "I am " + name + " and I like otters!";
}

void	Victim::getPolymorphed() const {
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}

std::string	Victim::getName(void) {
	return name;
}

void Victim::setName(std::string str) {
	name = str;
}

std::ostream& operator<<(std::ostream& out, Victim& victim) {
	out << victim.introduce() << std::endl;
	return out;
}
