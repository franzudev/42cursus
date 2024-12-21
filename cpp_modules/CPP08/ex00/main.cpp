#include "easyfind.hpp"

int main() {
	int myInts[] = { 10, 20, 30, 40, 50 };
	std::vector<int> myVector(std::begin(myInts), std::end(myInts));
	try {
		std::vector<int>::iterator testVector = easyfind(myVector, 31);
		std::cout << *testVector.base() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> myDeque;
	for (int i = 0; i < 5; i++)
		myDeque.push_back(myInts[i]);
	try {
		std::deque<int>::iterator testDeque = easyfind(myDeque, 30);
		std::cout << *testDeque << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> mylist;
	for (int i = 0; i < 5; i++)
		mylist.push_back(myInts[i]);
	try {
		std::list<int>::iterator testList = easyfind(mylist, 31);
		std::cout << *testList << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
