//
// Created by Federico Francois on 7/15/21.
//

#include "span.hpp"

int main() {
	Span span;
	Span span1(15000);
	std::vector<int> vector;
	for (int i = 0; i < 15000; i++)
		vector.push_back(i);

	try {
		span.addNumber(10);
	} catch (std::exception &e) {
		std::cout << "full" << std::endl;
	}
	try {
		span1.addNumber(vector.begin(), vector.end());
	} catch (std::exception &e) {
		std::cout << "full" << std::endl;
	}
	try {
		span1.addNumber(345);
	} catch (std::exception &e) {
		std::cout << "full" << std::endl;
	}

	std::cout << span1.shortestSpan() << std::endl;
	std::cout << span1.longestSpan() << std::endl;
}
