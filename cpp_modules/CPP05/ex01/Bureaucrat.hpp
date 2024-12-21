//
// Created by Federico François on 25/06/21.
//

#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	const std::string	name;
	int					grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	const Bureaucrat& operator=(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	const std::string	getName() const;
	void				setName(std::string);
	int					getGrade() const;
	void				setGrade(int);
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(const Form&) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif //CPP05_BUREAUCRAT_HPP
