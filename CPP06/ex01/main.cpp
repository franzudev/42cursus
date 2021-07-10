//
// Created by Federico Francois on 7/10/21.
//

#include "Serializer.hpp"

int main() {
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Serializer serializer;
		std::cout << "test " << i << ": " << '\n';
		void *raw = serializer.serialize();
		Data *dt = serializer.deserialize(raw);

		std::cout << "\tidx:  " << dt->idx << '\n';
		std::cout << "\tname: " << dt->name << '\n';

		delete static_cast<char*>(raw);
		delete dt;
	}

	return (0);
}
