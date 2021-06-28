//
// Created by Federico François on 25/06/21.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): name(name) {
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
	return "Grade too low";
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}


unsigned int Bureaucrat::getGrade() const {
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