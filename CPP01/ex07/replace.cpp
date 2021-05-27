//
// Created by Federico Francois on 26/05/2021.
//

#include "replace.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid number of parameters" << std::endl;
		return -1;
	}
	Sed sed = Sed(argv[1], argv[2], argv[3]);
	sed.replace();
}
