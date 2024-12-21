//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat bureaucrat1("Sparrow", 1);
	Bureaucrat bureaucrat3("David", 150);
	ShrubberyCreationForm shrubberyCreationForm("home");
	RobotomyRequestForm robotomyRequestForm("Teddy");
	PresidentialPardonForm presidentialPardonForm("Pablo Escobar");

	/*
	 * Presidential Form
	*/
	std::cout << "********* Presidential Form Test *********" << std::endl << std::endl;
	try {
		presidentialPardonForm.beSigned(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	try
	{
		presidentialPardonForm.beSigned(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl << presidentialPardonForm << std::endl;
	try {
		presidentialPardonForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		presidentialPardonForm.execute(bureaucrat3);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}

	/*
	 * Robotomy Form
	*/
	std::cout << std::endl << "********* Robotomy Form Test *********" << std::endl << std::endl;
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.beSigned(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	try
	{
		robotomyRequestForm.beSigned(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat3);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat3);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		robotomyRequestForm.execute(bureaucrat3);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}


	/*
	 * Shrubbery Form
	*/
	std::cout << std::endl << "********* Shrubbery Form Test *********" << std::endl << std::endl;
	try {
		shrubberyCreationForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		shrubberyCreationForm.beSigned(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	try
	{
		shrubberyCreationForm.beSigned(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << "Sign Exception: " << e.what() << std::endl;
	}
	try {
		shrubberyCreationForm.execute(bureaucrat1);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	try {
		shrubberyCreationForm.execute(bureaucrat3);
	} catch(std::exception &e) {
		std::cout << "Exec Exception: " << e.what() << std::endl;
	}
	return (0);
}