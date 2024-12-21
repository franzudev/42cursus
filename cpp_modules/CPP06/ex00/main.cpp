//
// Created by Federico François on 29/06/21.
//
#include "Converter.hpp"

int		main(int ac, char **av) {
	if (ac != 2)
		return 1;
	Converter a(av[1]);
	return 0;
}
