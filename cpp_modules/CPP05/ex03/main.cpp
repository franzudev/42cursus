//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat bureaucrat1("John", 1);
	Bureaucrat bureaucrat3("David", 150);
	ShrubberyCreationForm shrubberyCreationForm("flat");
	RobotomyRequestForm robotomyRequestForm("Teddy");
	PresidentialPardonForm presidentialPardonForm("Dr. Octopus");

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

	std::cout << std::endl << "********* Intern Creation Test *********" << std::endl << std::endl;
	Intern someRandomIntern;
	Bureaucrat bureaucrat("Sparrow", 1);
	Form* rrf;
	Form* scf;
	Form* ppf;
	Form* fnf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl << *rrf << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	std::cout << std::endl << *scf << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Pablo Escobar");
	std::cout << std::endl << *ppf << std::endl;

	try {
		fnf = someRandomIntern.makeForm("test forms", "Test");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		rrf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		rrf->beSigned(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		ppf->beSigned(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		scf->beSigned(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		rrf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		ppf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		scf->execute(bureaucrat);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete scf;
	delete ppf;
	delete rrf;

	return (0);
}