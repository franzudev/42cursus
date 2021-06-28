//
// Created by Federico François on 25/06/21.
//

#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	const std::string	name;
	unsigned int		grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string name, unsigned int grade);
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
	unsigned int		getGrade() const;
	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif //CPP05_BUREAUCRAT_HPP
