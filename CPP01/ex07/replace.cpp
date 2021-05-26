//
// Created by Federico Francois on 26/05/2021.
//

#include "replace.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::cout << "Invalid number of parameters" << std::endl;
	std::ifstream ifs;
	std::ofstream ofs;
	std::string filename;
	std::string line;

	int	i = 0;
	while (argv[1][i])
		filename += argv[1][i++];
	filename += ".replace";
	ifs.open(argv[1]);
	ofs.open(filename, std::ios::out | std::ios::trunc);

	ifs >> line;
	std::cout << line << std::endl;
	ifs >> line;
	std::cout << line << std::endl;
	ifs >> line;
	std::cout << line << std::endl;
//	while (std::getline(ifs, line))
//	{
////		std::cout << line << std::endl;
//		ofs << line << std::endl;
//	}

	ofs.close();
	ifs.close();
}
