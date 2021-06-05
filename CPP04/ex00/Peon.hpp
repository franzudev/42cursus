//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_PEON_HPP
#define CPP04_PEON_HPP

#include "Victim.hpp"

class Peon: public Victim {
	Peon();

public:
	Peon(std::string name);
	~Peon();
	Peon(const Peon& peon);
	Peon& operator=(const Peon& peon);

	void	getPolymorphed(void) const;
};

#endif //CPP04_PEON_HPP
