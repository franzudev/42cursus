//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_SORCERER_HPP
#define CPP04_SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	std::string	name;
	std::string	title;
	Sorcerer();
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(const Sorcerer& sorcerer);
	Sorcerer& operator=(const Sorcerer& sorcerer);

	std::string		introduce(void);
	void 			polymorph(Victim const &) const;
	void 			polymorph(Peon const &) const;

	std::string 	getName(void);
	std::string 	getTitle(void);
	void			setName(std::string str);
	void			setTitle(std::string str);
};

std::ostream& operator<<(std::ostream& out, Sorcerer& sorcerer);

#endif //CPP04_SORCERER_HPP
