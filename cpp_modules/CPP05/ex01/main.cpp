//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	std::cout << bureaucrat1 << bureaucrat3 << std::endl;

	Form form("Worker's Rights", 30, 20);
	Form form1("Student's Rights", 15, 10);

	std::cout << form << std::endl << form1 << std::endl;
	try
	{
		form.beSigned(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	try {
		form.beSigned(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << form << std::endl;

	try
	{
		form1.beSigned(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	try {
		form1.beSigned(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << "Caught Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << form1 << std::endl;

	return (0);
}