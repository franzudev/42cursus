//
// Created by Federico François on 20/05/21.
//

#ifndef CPP01_PONY_HPP
#define CPP01_PONY_HPP

#include <iostream>

class Pony {
	int		legs;
	int		age;
	int		height;
	int		type;

public:
	Pony();
	Pony(int type);
	void	ponyRun(void);
	void	ponyEat(void);
	void	ponySleep(void);
};

#endif //CPP01_PONY_HPP
