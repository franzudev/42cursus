//
// Created by Federico François on 02/06/21.
//

#include <iostream>
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;


	std::cout << std::endl << std::endl << "ISpaceMarine copy:" << std::endl << std::endl;

	AssaultTerminator	*assault = new AssaultTerminator;
	ISpaceMarine		*assaultCopy = new AssaultTerminator(*assault);

	TacticalMarine		*tactical = new TacticalMarine;
	ISpaceMarine		*tacticalCopy = new TacticalMarine(*tactical);

	ISquad				*squad = new Squad;

	squad->push(assaultCopy);
	squad->push(tacticalCopy);

	std::cout << std::endl;

	std::cout << "Delete initial assault and tactical:" << std::endl;
	delete assault;
	delete tactical;

	std::cout << std::endl << "Delete squad made of copy marine:" << std::endl;
	delete squad;
	return (0);
}