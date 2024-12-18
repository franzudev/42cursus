//
// Created by Federico François on 31/05/21.
//

#ifndef CPP04_VICTIM_HPP
#define CPP04_VICTIM_HPP

#include <iostream>

class Victim {
protected:
	std::string	name;
	Victim();

public:
	Victim(std::string);
	virtual ~Victim();
	Victim(const Victim& victim);
	Victim& operator=(const Victim& victim);

	std::string	introduce(void);
	std::string	getName(void);
	void 		setName(std::string str);
	void		getPolymorphed(void) const;
};

std::ostream& operator<<(std::ostream& out, Victim& victim);

#endif //CPP04_VICTIM_HPP
