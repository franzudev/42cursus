//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
private:
	std::string		name;
	int	ap;
	AWeapon			*weapon;
public:
	Character();
	Character(std::string const & name);
	Character(const Character& character);
	~Character();
	Character& operator=(const Character& character);
	void				recoverAP();
	void				equip(AWeapon*);
	void 				attack(Enemy*);
	const AWeapon		*getWeapon() const;
	int					getAP() const;
	std::string const	getName() const;
	void				setName(std::string str);
};

std::ostream& operator<<(std::ostream& out, const Character& character);

#endif //CPP04_CHARACTER_HPP
