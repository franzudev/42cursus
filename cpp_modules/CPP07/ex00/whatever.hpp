#include <iostream>

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class T>
void swap(T &a, T &b) {
	T temp = b;

	b = a;
	a = temp;
}

template <class T>
T min(T a, T b) {
	if (a < b)
		return a;
	return b;
}

template <class T>
T max(T a, T b) {
	if (a > b)
		return a;
	return b;
}

class
TestClass {
public:
	TestClass( int n ) : _n( n ) {}
	bool operator==( TestClass const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( TestClass const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( TestClass const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( TestClass const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( TestClass const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( TestClass const & rhs ) const { return (this->_n <= rhs._n); }
	int _n;
};

std::ostream& operator<<(std::ostream &out, TestClass const &awesome) {
	out << awesome._n;
	return out;
}

#endif
