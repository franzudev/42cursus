//
// Created by Federico François on 25/06/21.
//

#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	const std::string		_name;
	const int				_signGrade;
	const int				_execGrade;
	bool					_signed;
	Form();
public:
	Form(const std::string, const int, const int);
	virtual ~Form();
	Form(const Form&);
	Form& operator=(const Form&);


	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	int						getSignGrade() const;
	int						getExecGrade() const;
	std::string				getName() const;
	bool					isSigned() const;
	void					beSigned(const Bureaucrat &bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif //CPP05_FORM_HPP
