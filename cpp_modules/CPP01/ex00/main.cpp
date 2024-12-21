//
// Created by Federico François on 20/05/21.
//

#include "Pony.hpp"

void	ponyOnTheStack() {
	Pony pony = Pony();

	pony.ponyRun();
	pony.ponyEat();
	pony.ponySleep();
}

void	ponyOnTheHeap() {
	Pony *pony;

	pony = new Pony(1);

	pony->ponyRun();
	pony->ponyEat();
	pony->ponySleep();

	delete pony;
}

int main()
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return 0;
}