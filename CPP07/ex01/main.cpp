//
// Created by Federico Francois on 7/14/21.
//

#include "iter.hpp"

int main() {
	std::cout << "***** String array *****" << std::endl;
	std::string testA[] = { "ciao", "sono", "un", "iterabile", "di", "prova" };
	iter(testA, 6, printElement);

	std::cout << std::endl << "***** Int array *****" << std::endl;
	int			testB[] = { 1, 2, 3, 4, 5 };
	iter(testB, 5, printElement);

	std::cout << std::endl << "***** Char array *****" << std::endl;
	char testC[] = { 'p', 'r', 'o', 'v', 'a' };
	iter(testC, 5, printElement);

	std::cout << std::endl << "***** Float array *****" << std::endl;
	float testD[] = { 1.0, 2.6, 4.7, 6.34, 3.34 };
	iter(testD, 5, printElement);

	return 0;
}
