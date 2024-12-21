//
// Created by Federico Francois on 7/10/21.
//

#include "Serializer.hpp"

int main() {
	Serializer serializer;
	Data *ptr = new Data();
	ptr->idx = 1;
	ptr->name = "prova";
	uintptr_t serialized = serializer.serialize(ptr);
	std::cout << "Serialized: " << serialized << std::endl;
	Data *deserialized = serializer.deserialize(serialized);

	std::cout << "Original pointer: " << ptr->idx << " " << ptr->name << std::endl;
	std::cout << "Deserialized object: " << deserialized->idx << " " << deserialized->name << std::endl;

	return (0);
}
