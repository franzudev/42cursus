#pragma once

#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class MutantStack: public std::stack<int> {
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack const &);
	MutantStack &operator=(MutantStack const &);

};

#endif //CPP08_MUTANTSTACK_HPP
