//
// Created by Federico François on 21/05/21.
//

#ifndef CPP_HUMAN_HPP
#define CPP_HUMAN_HPP

#include "Brain.hpp"

class Human {
	const Brain brain;
public:
	Human();
	std::string		identify(void) const;
	const Brain		*getBrain(void) const;
};

#endif //CPP_HUMAN_HPP
