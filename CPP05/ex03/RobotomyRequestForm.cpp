//
// Created by Federico François on 26/06/21.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("robotomy request", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(
		const RobotomyRequestForm &robotomyRequestForm): Form("robotomy request", robotomyRequestForm.getName(), robotomyRequestForm.getSignGrade(), robotomyRequestForm.getExecGrade()) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(
		const RobotomyRequestForm &robotomyRequestForm) {
	(void) robotomyRequestForm;

	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::cout << "* BRRRZZZZZ VRRRR BRZ *" << std::endl;
	if ((rand() % 2) != 0)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " hasn't been robotomized..." << std::endl;
}