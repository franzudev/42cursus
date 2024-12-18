//
// Created by Federico François on 31/05/21.
//

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
//	Sorcerer robert("Robert", "the Magnificent");
//	Victim jim("Jimmy");
//	Peon joe("Joe");
//	std::cout << robert << jim << joe;
//	robert.polymorph(jim);
//	robert.polymorph(joe);
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << "4" << jim << joe;

	robert.polymorph(jim);
	jim.getPolymorphed();
	robert.polymorph(joe);
	joe.getPolymorphed();
	robert.polymorph(static_cast<Victim>(joe));

	std::cout << "---" << std::endl;

	Sorcerer blank(robert);

	Victim franck(jim);
	Peon jean(joe);

	std::cout << blank << franck << jean;

	franck = jim;
	blank.polymorph(franck);
	franck.getPolymorphed();
	blank = robert;
	jean = joe;
	blank.polymorph(jean);
	jean.getPolymorphed();

	std::cout << "---" << std::endl;
	return 0;
}
