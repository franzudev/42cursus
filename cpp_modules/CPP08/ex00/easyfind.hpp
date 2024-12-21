//
// Created by Federico Francois on 7/15/21.
//

#ifndef CPP08_EASYFIND_HPP
#define CPP08_EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

class ElementNotFoundException: public std::exception {
	virtual const char* what() const throw() {
		return "Element not found;";
	}
};

template <class T>
typename T::iterator easyfind(T haystack, int needle) {
	typename T::iterator it;

	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it != haystack.end())
		return it;
	else
		throw ElementNotFoundException();
}

#endif //CPP08_EASYFIND_HPP
