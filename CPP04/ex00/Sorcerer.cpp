//
// Created by Federico François on 31/05/21.
//

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(std::string name, std::string title): name(name), title(title) {
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &sorcerer) {
	setName(sorcerer.name);
	setTitle(sorcerer.title);
}

Sorcerer& Sorcerer::operator=(const Sorcerer &sorcerer) {
	setName(sorcerer.name);
	setTitle(sorcerer.title);

	return *this;
}

std::string	Sorcerer::introduce(void) {
	return "I am " + name + ", " + title + ", and I like ponies!";
}

std::string	Sorcerer::getName(void) {
	return name;
}

void 	Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}

void 	Sorcerer::polymorph(Peon const &peon) const {
	peon.getPolymorphed();
}

void Sorcerer::setName(std::string str) {
	name = str;
}

std::string	Sorcerer::getTitle(void) {
	return title;
}

void Sorcerer::setTitle(std::string str) {
	title = str;
}

std::ostream& operator<<(std::ostream& out, Sorcerer& sorcerer) {
	out << sorcerer.introduce() << std::endl;
	return out;
}
