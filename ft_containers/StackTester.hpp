#pragma once

#pragma once

#define TEST_ARR_SIZE 1000

#ifdef USE_STL
# define STL "std: "
# include <iterator>
# include <stack>
# include <array>
# include <set>
namespace ft = std;
#else
# define STL "ft: "
# include "Bureaucrat.hpp"
# include "iterator.hpp"
# include "stack.hpp"
# include "is_integral.hpp"
#endif

#include <iostream>
#include "Timer.hpp"

template <class T, class Container>
struct StackTester {
	typedef ft::stack<T, Container>	stack_t;

	stack_t &stack;

	StackTester(std::string msg, stack_t &stack): stack(stack) {
		std::cout << msg << std::endl;
	};

	void printStack() {
		for (typename stack_t::iterator start = stack.begin(); start != stack.end(); start++)
			std::cout << *start;
		std::cout << std::endl;
	}

	void	printSizes() {
		std::cout << std::endl;
		std::cout << "Size:  " << stack.size() << std::endl;
		std::cout << "Empty: " << stack.empty() << std::endl;
		std::cout << std::endl;
	}

	void	testTop() {
		printSizes();
		Timer test(std::string(STL) + "Testing top() ");
		std::cout << stack.top() << std::endl;
		test.getDiff();
		printSizes();
//		printStack();
	}
	void	testPush(const T& value) {
		printSizes();
		Timer test(std::string(STL) + "Testing push(const T& value) ");
		stack.push(value);
		test.getDiff();
		printSizes();
//		printStack();
	}
	void	testPop() {
		printSizes();
		Timer test(std::string(STL) + "Testing pop() ");
		stack.pop();
		test.getDiff();
		printSizes();
//		printStack();
	}

private:
	StackTester();
};


template <typename T, typename Container>
void	testStackFunctions(std::string  msg, ft::stack<T, Container> &toTest)
{
	StackTester<T, Container>	tester(std::string(STL) + msg, toTest);
	ft::stack<T, Container> toTest2(toTest);
	StackTester<T, Container>	tester2(std::string(STL) + msg, toTest2);

	tester.testTop();
	tester.testPush(toTest.top());
	tester.testPop();
	tester2.testTop();
	tester2.testPush(toTest2.top());
	tester2.testPop();
	std::cout << "Is == " << (toTest == toTest2) << std::endl;
	std::cout << "Is <  " << (toTest < toTest2) << std::endl;
	std::cout << "Is <= " << (toTest <= toTest2) << std::endl;
	std::cout << "Is >  " << (toTest > toTest2) << std::endl;
	std::cout << "Is >= " << (toTest >= toTest2) << std::endl;
}

/*void	testStringStackFunctions(std::string  msg, ft::stack<T> &toTest)
{
	StackTester<std::string>	tester(std::string(STL) + msg, toTest);
	std::string randArray[TEST_ARR_SIZE];
	for (unsigned int i = 0; i < TEST_ARR_SIZE; ++i)
		randArray[i] = std::to_string(i);
	ft::stack<std::string> vectorItTest(std::begin(randArray), std::end(randArray));

	tester.testTemplatedAssign("Templated Assign", std::begin(randArray), std::end(randArray));
	tester.clearVector();
	tester.testSizedAssign("Sized Assign", 100, std::to_string(1));
	tester.testPushBack(*(vectorItTest.begin() + 5));
	tester.clearVector();
	tester.testPushBack(*(vectorItTest.begin() + 10));
	tester.testPopBack();
	tester.testSingleInsert(std::to_string(4));
	tester.testSizedInsert(10, std::to_string(5));
	tester.testIteratorsInsert(vectorItTest.begin(), vectorItTest.end());
	tester.testErase();
	tester.testEraseIterators();
}*/

