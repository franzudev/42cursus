//
// Created by Federico Francois on 7/14/21.
//

#ifndef CPP07_ITER_HPP
#define CPP07_ITER_HPP

#include <iostream>

template <class T>
void printElement(T const &el) {
	std::cout << el << std::endl;
}

template <class T>
void iter(T const *arr, int arrLen, void (*f)(T const &el)) {
	for (int i = 0; i < arrLen; i++) {
		f(arr[i]);
	}
}

#endif //CPP07_ITER_HPP
