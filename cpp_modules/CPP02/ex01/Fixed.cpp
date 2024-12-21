//
// Created by Federico Francois on 27/05/2021.
//

#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = (val << Fixed::fractionalBits);
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(val * (1 << Fixed::fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = fixed.getRawBits();

	return *this;
}

std::ostream &operator << (std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}

int Fixed::getRawBits() const {
//	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

int Fixed::toInt() const {
	return fixedPointValue >> Fixed::fractionalBits;
}

float	Fixed::toFloat() const {
	return ((float)fixedPointValue / (float)(1 << Fixed::fractionalBits));
}
