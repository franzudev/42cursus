//
// Created by Federico Francois on 7/15/21.
//

#include "span.hpp"

Span::Span(): size(0) {}

Span::~Span() {}

Span::Span(unsigned int size): size(size) {}

void Span::addNumber(int number) {
	if (values >= size)
		throw std::exception();
	vector.push_back(number);
	values++;
}

int Span::shortestSpan() {
	if (values < 2)
		throw std::exception();
	std::sort(vector.begin(), vector.end());
	return *(vector.begin() + 1) - *vector.begin();
}

int Span::longestSpan() {
	if (values < 2)
		throw std::exception();
	return *std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end());
}


