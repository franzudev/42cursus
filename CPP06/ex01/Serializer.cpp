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

Data * Serializer::deserialize(uintptr_t raw){
	Data *d = new Data;

	d->idx = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	d->name = std::string(static_cast<char*>(raw), 8);
	return (d);
}

uintptr_t Serializer::serialize(Data *ptr) {
	static std::string alphabet = "0123456789" \
		"abcdefghijklmopqrstuvxyz" \
		"ABCDEFGHIJKLMOPQRSTUVXYZ";
	static size_t alphabetLength = alphabet.length();
	char *raw;

	raw = new char[20];
	for (int i = 0; i < 8; i++)
		raw[i] = alphabet[rand() % alphabetLength];
	*reinterpret_cast<int*>(raw + 8) = rand() % 424242;
	for (int i = 0; i < 8; i++)
		raw[i + 12] = alphabet[rand() % alphabetLength];
	return (raw);
}
