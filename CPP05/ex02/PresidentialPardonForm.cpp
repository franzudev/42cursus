//
// Created by Federico François on 26/06/21.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("presidential pardon", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm &presidentialPardonForm): Form("presidential pardon", presidentialPardonForm.getName(), presidentialPardonForm.getSignGrade(), presidentialPardonForm.getExecGrade()) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(
		const PresidentialPardonForm &presidentialPardonForm) {
	Form("presidential pardon", presidentialPardonForm.getName(), presidentialPardonForm.getSignGrade(), presidentialPardonForm.getExecGrade());

	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}