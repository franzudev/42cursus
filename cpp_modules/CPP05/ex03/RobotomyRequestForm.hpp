//
// Created by Federico François on 26/06/21.
//

#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form {
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string &target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequestForm);

	void	execute(const Bureaucrat &executor) const;
};

#endif //CPP05_ROBOTOMYREQUESTFORM_HPP
