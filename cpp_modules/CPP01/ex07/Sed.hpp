//
// Created by Federico Francois on 27/05/2021.
//

#ifndef CPP01_SED_HPP
#define CPP01_SED_HPP

#include <fstream>
#include <iostream>

class Sed {
	std::string		_inputFileName;
	std::string		_strToFind;
	std::string		_strToReplace;

	std::string		getOutpuFileName();
	std::string		generateSubstitute(std::string line);
public:
	Sed();
	Sed(std::string inputFileName, std::string strToFind, std::string strToReplace);
	~Sed();
	void	replace();
};

#endif //CPP01_SED_HPP
