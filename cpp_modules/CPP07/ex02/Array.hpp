//
// Created by Federico Francois on 7/14/21.
//

#ifndef CPP07_ARRAY_HPP
#define CPP07_ARRAY_HPP

#include <iostream>

template <class T>
class Array {
public:
	T *arr;
	unsigned int length;

	Array(): arr(new T[0]), length(0) {}
	Array(unsigned int size): arr(new T[size]), length(size) {
		for (unsigned i = 0; i < size; i++)
			arr[i] = 0;
	}
	~Array() {
		delete[] arr;
	}
	Array(Array<T> const &array) {
		*this = array;
	}
	Array<T>& operator=(Array<T> const &array) {
		if (this == &array)
			return *this;
		arr = new T[array.length];
		length = array.length;
		for (unsigned i = 0; i < array.length; i++) {
			arr[i] = array.arr[i];
		}
		return *this;
	}
	T& operator[] (unsigned int index)
	{
		if ((index < 0 || index >= length) && length >= 0)
			throw std::exception();
		return arr[index];
	}
	unsigned int	size() {
		return length;
	}

};

#endif //CPP07_ARRAY_HPP
