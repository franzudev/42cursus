//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	*this = bureaucrat;
}

const Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	setGrade(bureaucrat.grade);

	return *this;
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "\e[31mGrade too low\e[0m";
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "\e[31mGrade too high\e[0m";
}

void Bureaucrat::signForm(const Form &form) const{
	if (grade > form.getSignGrade())
		std::cout << getName() << " cannot sign form " << form.getName() << " because grade is too low." << std::endl;
	else
		std::cout << getName() << " signs form " << form.getName() << std::endl;

}

int Bureaucrat::getGrade() const {
	return grade;
}

const std::string Bureaucrat::getName() const {
	return name;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	os << std::endl;
	return os;
}