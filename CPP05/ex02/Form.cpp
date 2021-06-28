//
// Created by Federico François on 25/06/21.
//

#include "Form.hpp"

Form::~Form() {}

Form::Form(const std::string name, const std::string target, const int sign, const int exec):
		_name(name), _target(target), _signGrade(sign), _execGrade(exec), _signed(false) {
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form.getName()), _target(form.getTarget()), _signGrade(form.getSignGrade()), _execGrade(form._execGrade), _signed(false) {}

Form & Form::operator=(const Form &form) {
	(void)form;
	_signed = false;

	return *this;
}

std::string Form::getName() const {
	return _name;
}

std::string Form::getTarget() const {
	return _target;
}

int Form::getExecGrade() const {
	return _execGrade;
}

int Form::getSignGrade() const {
	return _signGrade;
}

bool Form::isSigned() const{
	return _signed;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
	bureaucrat.signForm(*this);
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char * Form::GradeTooLowException::what() const throw() {
	return "\e[31mGrade too low\e[0m";
}

const char * Form::GradeTooHighException::what() const throw() {
	return "\e[31mGrade too high\e[0m";
}

const char * Form::UnsignedException::what() const throw() {
	return "\e[31mForm unsigned\e[0m";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form Name: " << form.getName() << std::endl;
	out << "Form Target: " << form.getTarget() << std::endl;
	out << "Form minimum grade for sign: " << form.getSignGrade() << std::endl;
	out << "Form minimum grade for execution: " << form.getExecGrade() << std::endl;
	out << "Form signed: " << (form.isSigned() ? "Yes" : "No") << std::endl;

	return out;
}

void Form::execute(const Bureaucrat &executor) const {
	executor.executeForm(*this);
	if (!isSigned())
		throw Form::UnsignedException();
	if (executor.getGrade() > getExecGrade())
		throw Form::GradeTooLowException();
}