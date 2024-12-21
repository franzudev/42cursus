//
// Created by Federico François on 26/06/21.
//

#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form {
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string &target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardonForm);

	void	execute(const Bureaucrat &executor) const;
};

#endif //CPP05_PRESIDENTIALPARDONFORM_HPP
