//
// Created by Federico François on 26/06/21.
//

#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string &target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);

	class FileOpenException: public std::exception {
		virtual const char* what() const throw();
	};

	void	execute(const Bureaucrat &executor) const;
};

#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
