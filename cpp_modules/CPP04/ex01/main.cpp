//
// Created by Federico François on 31/05/21.
//

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* c = new SuperMutant();
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->equip(pf);
	me->attack(c);
	me->recoverAP();
	me->attack(c);
	me->attack(c);
	me->recoverAP();
	me->attack(c);

	delete me;
	delete pr;
	return 0;
}
