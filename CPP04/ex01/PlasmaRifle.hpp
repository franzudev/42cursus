//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_PLASMARIFLE_HPP
#define CPP04_PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon {
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle& plasmaRifle);
	~PlasmaRifle();
	PlasmaRifle& operator=(const PlasmaRifle& plasmaRifle);

	void attack() const;
};

#endif //CPP04_PLASMARIFLE_HPP
