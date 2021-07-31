#include "VectorTester.hpp"
#include "StackTester.hpp"
#include "Bureaucrat.hpp"
//#include <iostream>
//#include <list>
#include "common.hpp"

#define TESTED_TYPE int

int main() {
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
	return (0);
}

/*int		main(void)
{
	const int size = 5;
	ft::vector<TESTED_TYPE> vct(size);
	ft::vector<TESTED_TYPE>::iterator it = vct.begin();
	ft::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	prepost_incdec(vct);

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
	return (0);
}
*/

//int		main(void)
//{
//	const int size = 5;
//	ft::vector<TESTED_TYPE> vct(size);
//	ft::vector<TESTED_TYPE>::iterator it_ = vct.begin();
//	ft::vector<TESTED_TYPE>::reverse_iterator it(it_);
//
//	for (int i = 0; i < size; ++i)
//		vct[i] = (i + 1) * 5;
//	printSize(vct);
//
//	std::cout << (it_ == it.base()) << std::endl;
//	std::cout << (it_ == (it + 3).base()) << std::endl;
//
//	std::cout << *(it.base() + 1) << std::endl;
//	std::cout << *(it - 3) << std::endl;
//	std::cout << *(it - 3).base() << std::endl;
//	it -= 3;
//	std::cout << *it.base() << std::endl;
//
//	std::cout << "TEST OFFSET" << std::endl;
//	std::cout << *(it) << std::endl;
//	std::cout << *(it).base() << std::endl;
//	std::cout << *(it - 0) << std::endl;
//	std::cout << *(it - 0).base() << std::endl;
//	std::cout << *(it - 1).base() << std::endl;
//
//	return (0);
//}
