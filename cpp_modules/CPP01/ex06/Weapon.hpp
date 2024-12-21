//
// Created by Federico François on 21/05/21.
//

#ifndef CPP_WEAPON_HPP
#define CPP_WEAPON_HPP

#include <iostream>

class Weapon {
	std::string _type;
public:
	Weapon();
	Weapon(std::string const &type);
	~Weapon();
	std::string const	&getType() const;
	void 				setType(std::string const &type);
};

#endif //CPP_WEAPON_HPP
