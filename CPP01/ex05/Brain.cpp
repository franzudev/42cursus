//
// Created by Federico François on 21/05/21.
//

#include "Brain.hpp"

Brain::Brain() {}

std::string Brain::identify() const{
	const long address = (long)this;
	std::stringstream ss;

	ss << "0x" << std::uppercase << std::hex << address;
	return ss.str();
}
