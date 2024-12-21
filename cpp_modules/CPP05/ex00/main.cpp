//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("Jack", 0);
	} catch (std::exception &e) {
		std::cout << "Cannot create Jack bureaucrat. " << e.what() << std::endl;
	}
	Bureaucrat bureaucrat1("Sparrow", 1);
	bureaucrat1.decrementGrade();

	try {
		Bureaucrat bureaucrat2("John", 151);
	} catch (std::exception &e) {
		std::cout << "Cannot create John bureaucrat. " << e.what() << std::endl;
	}
	Bureaucrat bureaucrat3("David", 150);
	bureaucrat3.incrementGrade();

	std::cout << bureaucrat1 << bureaucrat3;

	return (0);
}