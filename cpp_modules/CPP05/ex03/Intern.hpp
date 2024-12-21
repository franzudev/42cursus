//
// Created by Federico François on 27/06/21.
//

#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern;

typedef Form* (Intern::*funcs)(const std::string);

class Intern {
public:
	funcs 		funcs_[3];
	std::string	forms_[3];

	Intern();
	~Intern();
	Intern(Intern const &);
	Intern &operator = (Intern const &);
	Form *makeForm(const std::string, const std::string);
	Form *makeShrubbery(const std::string);
	Form *makeRobotomy(const std::string);
	Form *makePresidential(const std::string);
	class FormNotFoundException: public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //CPP05_INTERN_HPP
