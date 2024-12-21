#include "mutantstack.hpp"

void	print_values(MutantStack<int>::iterator start, MutantStack<int>::iterator end, std::list<int>::iterator lsStart, std::list<int>::iterator lsEnd) {
	std::cout << "\x1b[92m Values :\x1b[0m" << std::endl;
	std::cout << std::setw(15) << std::right << "MutantStack" << " | " << std::setw(15) << std::left << "std::list" << std::endl;
	while (start != end || lsStart != lsEnd)
	{
		std::cout << std::setw(15) << std::right << *start << " | " << std::setw(15) << std::left << *lsStart << std::endl;
		++start;
		++lsStart;
	}
}

void	print_pushed(std::string pushed) {
	std::cout << "\x1b[92m Pushing :\x1b[0m { " << pushed << " }" << std::endl;
}

int main(void)
{
	std::cout << " *********** Subject's test ***********" << std::endl;
	MutantStack<int> smstack;
	smstack.push(5);
	smstack.push(17);
	std::cout << smstack.top() << std::endl;
	smstack.pop();
	std::cout << smstack.size() << std::endl;
	smstack.push(3);
	smstack.push(5);
	smstack.push(737);
	smstack.push(0);
	MutantStack<int>::iterator it = smstack.begin();
	MutantStack<int>::iterator ite = smstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> sm(smstack);

	std::cout << " *********** Mine's test ***********" << std::endl;

	MutantStack<int> mstack;
	std::list<int>	lst;
	MutantStack<int>::iterator	mit;
	MutantStack<int>::iterator	mitend;
	std::list<int>::iterator	lsit;
	std::list<int>::iterator	lsitend;

	print_pushed("32, 77");
	mstack.push(32);
	lst.push_back(32);
	mstack.push(77);
	lst.push_back(77);

	mit = mstack.begin();
	mitend = mstack.end();
	lsit =	lst.begin();
	lsitend = lst.end();
	print_values(mit, mitend, lsit, lsitend);

	std::cout << "\x1b[92m Popping both\x1b[0m" << std::endl;
	mstack.pop();
	lst.pop_back();

	mit = mstack.begin();
	mitend = mstack.end();
	lsit =	lst.begin();
	lsitend = lst.end();
	print_values(mit, mitend, lsit, lsitend);

	print_pushed("12, 46, 689");
	mstack.push(12);
	mstack.push(46);
	mstack.push(689);
	lst.push_back(12);
	lst.push_back(46);
	lst.push_back(689);

	std::cout << "\x1b[92m Top:\x1b[0m" << std::endl;
	std::cout << std::setw(15) << std::right << "MutantStack" << " | " << std::setw(15) << std::left << "std::list" << std::endl;
	std::cout << std::setw(15) << std::right << mstack.top() << " | " << std::setw(15) << std::left << lst.back() << std::endl;

	mit = mstack.begin();
	mitend = mstack.end();
	lsit =	lst.begin();
	lsitend = lst.end();

	++mit;
	--mit;
	++lsit;
	--lsit;
	print_values(mit, mitend, lsit, lsitend);

	std::stack<int> s(mstack);
	std::list<int>	l(lst);

	std::cout << "\x1b[92m Top:\x1b[0m" << std::endl;
	std::cout << std::setw(15) << std::right << "MutantStack" << " | " << std::setw(15) << std::left << "std::list" << std::endl;
	std::cout << std::setw(15) << std::right << s.top() << " | " << std::setw(15) << std::left << l.back() << std::endl;

	MutantStack<int>	s_stack = mstack;
	std::list<int>		s_lst = lst;

	print_pushed("2, 8, 12");

	s_stack.push(2);
	s_stack.push(8);
	s_stack.push(12);
	s_lst.push_back(2);
	s_lst.push_back(8);
	s_lst.push_back(12);

	mit = s_stack.begin();
	mitend = s_stack.end();
	lsit = s_lst.begin();
	lsitend = s_lst.end();

	print_values(mit, mitend, lsit, lsitend);
	std::cout << "\x1b[92m Final sizes:\x1b[0m" << std::endl;
	std::cout << std::setw(15) << std::right << "MutantStack" << " | " << std::setw(15) << std::left << "std::list" << std::endl;
	std::cout << std::setw(15) << std::right << s_stack.size() << " | " << std::setw(15) << std::left << s_lst.size() << std::endl;

	return (0);
}
