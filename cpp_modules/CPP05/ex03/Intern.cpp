//
// Created by Federico François on 27/06/21.
//

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	funcs_[0] = &Intern::makeShrubbery;
	funcs_[1] = &Intern::makeRobotomy;
	funcs_[2] = &Intern::makePresidential;
	forms_[0] = "shrubbery creation";
	forms_[1] = "robotomy request";
	forms_[2] = "presidential pardon";
}
Intern::~Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern & Intern::operator=(const Intern &intern) {
	(void)intern;
	return *this;
}

const char * Intern::FormNotFoundException::what() const throw() {
	return "\e[31mForm doesn't exist\e[0m";
}

Form * Intern::makeForm(const std::string name, const std::string target) {
	for (int i = 0; i < 3; i++){
		if (name == forms_[i]) {
			std::cout << "Intern creates " << forms_[i] << std::endl;
			return (this->*(funcs_[i]))(target);
		}
	}
	throw Intern::FormNotFoundException();
}

Form * Intern::makeShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

Form * Intern::makeRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::makePresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}