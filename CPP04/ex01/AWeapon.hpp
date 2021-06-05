//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_AWEAPON_HPP
#define CPP04_AWEAPON_HPP

#include <iostream>

class AWeapon {
protected:
	AWeapon();
	std::string		name;
	unsigned int	damage;
	unsigned int	apCost;
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(const AWeapon& aWeapon);
	AWeapon& operator=(const AWeapon& aWeapon);
	virtual ~AWeapon();
	std::string const	&getName() const;
	int					getAPCost() const;
	int					getDamage() const;
	void				setName(std::string str);
	void				setAPCost(unsigned int val);
	void				setDamage(unsigned int val);
	virtual void attack() const = 0;
};

#endif //CPP04_AWEAPON_HPP
