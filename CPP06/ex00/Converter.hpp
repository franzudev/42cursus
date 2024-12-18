//
// Created by Federico Francois on 7/9/21.
//

#ifndef CPP06_CST_H
#define CPP06_CST_H

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>

class Converter
{
	Converter();
	Converter(const Converter& src);
	Converter& operator=(const Converter& src);

	void	fromChar(std::string str);
	void	fromInvalid();
	void	fromDouble();
	void	fromLimits(std::string str);
	double	dval;

public:
	Converter(std::string _str);
	~Converter();
};


#endif //CPP06_CST_H
