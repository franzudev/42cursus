//
// Created by Federico Francois on 27/05/2021.
//

#include "Sed.hpp"

Sed::Sed() {};

Sed::Sed(std::string inputFileName, std::string strToFind, std::string strToReplace): _inputFileName(inputFileName), _strToFind(strToFind), _strToReplace(strToReplace) {}

Sed::~Sed() {}

std::string Sed::getOutpuFileName()
{
	int	i = 0;
	std::string filename;

	while (_inputFileName[i])
		filename += _inputFileName[i++];
	filename += ".replace";

	return filename;
}

std::string Sed::searchAndReplace(std::string line)
{
	std::string res;
	std::size_t found;
	std::size_t i;
	std::size_t strFindLen;

	found = -1;
	strFindLen = _strToFind.length();
	while ((found = line.find(_strToFind, found + 1)) != std::string::npos)
	{
		while (i < found)
			res += line[i++];
		i = 0;
		while (_strToReplace[i])
			res += _strToReplace[i++];
		i += found + (strFindLen - i);
	}
	while (line[i])
		res += line[i++];
	return res;
}

void Sed::replace()
{
	std::string		line;
	std::string		replaced;
	std::ifstream	inputFile;
	std::ofstream	outputFile;

	inputFile.open(_inputFileName);
	outputFile.open(getOutpuFileName(), std::ios::out | std::ios::trunc);
	while (std::getline(inputFile, line))
	{
		if (line.find(_strToFind))
			replaced = searchAndReplace(line);
		else
			replaced = line;
		outputFile << replaced << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
