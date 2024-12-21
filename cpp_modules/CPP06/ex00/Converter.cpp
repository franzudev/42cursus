//
// Created by Federico Francois on 7/9/21.
//

#include "Converter.hpp"

Converter::Converter()	{}

Converter::Converter(std::string str): dval(0)
{
	try
	{
		if ((str == "inff") || (str == "-inff") || (str == "+inff") || (str == "inf")
		|| (str == "-inf") || (str == "+inf") || (str == "nanf") || (str == "nan"))
			fromLimits(str);
		else
		{
			dval = std::stod(str);
			fromDouble();
		}
	}
	catch(const std::exception& e)
	{
		if (str.length() == 1)
			fromChar(str);
		else
			fromInvalid();
	}
}

Converter::Converter(const Converter& src)
{
	(void)src;
}

Converter::~Converter()	{}

Converter&		Converter::operator=(const Converter& src)
{
	(void)src;
	return *this;
}

void	Converter::fromChar(std::string str)
{
	if (str[0] > 31 && str[0] < 127)
		std::cout << "Char: '" << str[0] << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(str.c_str()[0]) << std::endl;
	std::cout << "Float: " << static_cast<float>(str.c_str()[0]) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(str.c_str()[0]) << ".0" << std::endl;
	return ;
}

void	Converter::fromDouble()
{
//	std::cout.precision(7);
	if (dval >= 32 && dval < 127)
		std::cout << "Char: '" << static_cast<char>(dval) << "'" << std::endl;
	else if (dval >= 0 && dval <= 31)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
	if (dval >= std::numeric_limits<int>::min() && dval <= std::numeric_limits<int>::max())
		std::cout << "Int: " << static_cast<int>(dval) << std::endl;
	else
		std::cout << "Int: impossible" << std::endl;
	if (dval > std::numeric_limits<float>::max() || dval < std::numeric_limits<float>::min()) {
		std::cout << "Float: " << static_cast<float>(dval) << "f" << std::endl;
		std::cout << "Double: " << dval << std::endl;
	}
	else {
		if (static_cast<float>(dval) == static_cast<int>(dval)) {
			std::cout << "Float: " << static_cast<float>(dval) << ".0f" << std::endl;
			std::cout << "Double: " << dval << ".0" << std::endl;
		} else {
			std::cout << "Float: " << static_cast<float>(dval) << "f"
					  << std::endl;
			std::cout << "Double: " << dval << std::endl;
		}
	}
}

void	Converter::fromLimits(std::string str)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossibile" << std::endl;
	if ((str == "nan") || (str == "nanf")) {
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	} else if ((str == "-inf") || (str == "-inff")) {
		std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: -inf" << std::endl;
	} else {
		std::cout << "Float: inff" << std::endl;
		std::cout << "Double: inf" << std::endl;
	}
}

void	Converter::fromInvalid(void)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossibile" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;
}
