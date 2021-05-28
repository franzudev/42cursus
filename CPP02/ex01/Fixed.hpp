//
// Created by Federico Francois on 27/05/2021.
//

#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	int					fixedPointValue;
	static const int	fractionalBits = 8;
public:
	Fixed();
	virtual ~Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator << (std::ostream &out, Fixed const &fixed);

#endif //CPP02_FIXED_HPP
