//
// Created by Federico Francois on 7/10/21.
//

#ifndef CPP06_SERIALIZER_HPP
#define CPP06_SERIALIZER_HPP

#include <iostream>

struct Data {
	int			idx;
	std::string	name;
};

class Serializer {
public:
	Serializer();
	~Serializer();
	Serializer(Serializer const &);
	Serializer& operator=(Serializer const &);

	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);

};

#endif //CPP06_SERIALIZER_HPP
