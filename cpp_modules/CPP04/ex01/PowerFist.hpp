//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_POWERFIST_HPP
#define CPP04_POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist: public AWeapon {
public:
	PowerFist();
	PowerFist(const PowerFist& powerFist);
	~PowerFist();
	PowerFist& operator=(const PowerFist& powerFist);

	void attack() const;
};

#endif //CPP04_POWERFIST_HPP
