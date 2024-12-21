//
// Created by Federico François on 03/06/21.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character: public ICharacter {
	std::string		name;
	AMateria**		inventory;
	unsigned int	inventorySize;

	Character();
public:
	Character(const std::string& name);
	Character(const Character& character);
	~Character();
	Character& operator=(const Character& character);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif //CPP04_CHARACTER_HPP
