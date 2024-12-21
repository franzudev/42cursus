//
// Created by Federico Francois on 7/10/21.
//

#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &serializer) {
	(void)serializer;
}

Serializer & Serializer::operator=(const Serializer &serializer) {
	(void)serializer;
	return *this;
}

Data * Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}
