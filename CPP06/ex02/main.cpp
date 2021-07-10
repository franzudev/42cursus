//
// Created by Federico Francois on 7/10/21.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int r;

	r = (rand() % 3) + 1;
	if (r % 3 == 0) {
		std::cout << "generating A" << std::endl;
		return new A();
	}
	if (r % 3 == 1) {
		std::cout << "generating B" << std::endl;
		return new B();
	}
	std::cout << "generating C" << std::endl;
	return new C();
}

void identify(Base* p) {
	std::cout << "Pointer type: ";
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	std::cout << "Reference type: ";
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	} catch (std::bad_cast &e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	} catch (std::bad_cast &e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	} catch (std::bad_cast &e) {}
}

int main() {
	Base *p;
	int i = 0;

	while (i < 10) {
		p = generate();
		identify(p);
		identify(*p);
		delete p;
		i++;
	}
	return 0;
}
