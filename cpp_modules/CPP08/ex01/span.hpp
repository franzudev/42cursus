//
// Created by Federico Francois on 7/15/21.
//

#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class Span {
	std::vector<int>	vector;
	unsigned int		values;
	unsigned int		size;

	Span(Span const &);
	Span &operator=(Span const &);
public:
	Span();
	Span(unsigned int size);
	~Span();

	void	addNumber(int);

	template <class T>
	void addNumber(T start, T end)
	{
		if (end - start > size)
			throw std::exception();
		values = end - start;
		//	https://stackoverflow.com/a/23215243/9549541
		std::copy(start, end, std::back_inserter(vector));
	}

	int	shortestSpan();
	int	longestSpan();
};

#endif //CPP08_SPAN_HPP
