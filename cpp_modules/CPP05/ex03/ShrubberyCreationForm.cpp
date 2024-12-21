//
// Created by Federico François on 26/06/21.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("shrubbery creation", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(
		const ShrubberyCreationForm &shrubberyCreationForm): Form("shrubbery creation", shrubberyCreationForm.getName(), shrubberyCreationForm.getSignGrade(), shrubberyCreationForm.getExecGrade()) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &shrubberyCreationForm) {
	(void)shrubberyCreationForm;

	return *this;
}

const char * ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "\e[31mCan't open file\e[0m";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::ofstream output;

	output.open(getTarget() + "_shrubbery");
	if (!output.is_open() || output.bad())
		throw ShrubberyCreationForm::FileOpenException();
	if ((rand() % 2) != 0)
		output << "      /\\      \n"
				  "     /\\*\\     \n"
				  "    /\\O\\*\\    \n"
				  "   /*/\\/\\/\\   \n"
				  "  /\\O\\/\\*\\/\\  \n"
				  " /\\*\\/\\*\\/\\/\\ \n"
				  "/\\O\\/\\/*/\\/O/\\\n"
				  "      ||      \n"
				  "      ||      \n"
				  "      ||" << std::endl;
	else
		output << "      /\\      \n"
				  "     /\\*\\     \n"
				  "    /\\O\\*\\    \n"
				  "   /*/\\/\\/\\   \n"
				  "  /\\O\\/\\*\\/\\  \n"
				  " /\\*\\/\\*\\/\\/\\ \n"
				  "/\\O\\/\\/*/\\/O/\\\n"
				  "      \\\\      \n"
				  "        \\\\    \n"
				  "          \\\\" << std::endl;
	output.close();
}