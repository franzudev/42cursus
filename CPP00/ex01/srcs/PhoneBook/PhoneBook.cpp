//
// Created by Federico François on 20/05/21.
//

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void	PhoneBook::start() {
	std::string cmd;

	std::cout << "$>";
	std::getline(std::cin, cmd);
	while (!std::cin.eof())
	{
		if (cmd == "SEARCH")
			searchContact();
		else if (cmd == "ADD")
			insertInfo();
		else if (cmd == "EXIT")
			break;
		else if (!std::cin.eof())
			std::cout << "COMMAND NOT FOUND" << std::endl;
		std::cout << "$>";
		std::getline(std::cin, cmd);
	}
	std::cin.clear();
	if (cmd == "EXIT")
		std::cout << "BYE! SEE YOU SOON!" << std::endl;
	else
	{
		std::cout << "";
		std::cout << std::endl << "BYE! SEE YOU SOON!" << std::endl;
	}
}

PhoneBook::PhoneBook() {
	book_size = 0;
}

void PhoneBook::insertInfo(void) {
	ContactInfo	info;

	std::cout << "INSERT FIRST NAME" << std::endl;
	std::getline(std::cin, info.name);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT LAST NAME" << std::endl;
	std::getline(std::cin, info.surname);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT NICKNAME" << std::endl;
	std::getline(std::cin, info.nickname);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT LOGIN" << std::endl;
	std::getline(std::cin, info.login);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT POSTAL ADDRESS" << std::endl;
	std::getline(std::cin, info.postal_code);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT EMAIL ADDRESS" << std::endl;
	std::getline(std::cin, info.email);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT PHONE NUMBER" << std::endl;
	std::getline(std::cin, info.phone);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT BIRTHDAY DATE" << std::endl;
	std::getline(std::cin, info.birthday);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT FAVORITE MEAL" << std::endl;
	std::getline(std::cin, info.meal);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT UNDERWEAR COLOR" << std::endl;
	std::getline(std::cin, info.underwear);
	if (std::cin.eof())
		return ;
	std::cout << "INSERT DARKEST SECRET" << std::endl;
	std::getline(std::cin, info.secret);
	if (std::cin.eof())
		return ;

	return addContact(Contact(info));
}

void	PhoneBook::addContact(Contact contact) {
	if (book_size == 9)
		return ;
	if (book_size == 0)
		book_size++;
	book[book_size++ - 1] = contact;
}

void	PhoneBook::printParams(std::string str, int toPrint)
{
	if (toPrint > 9)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::left << str << '|';
}

void	PhoneBook::searchContact(void) {
	std::string	input;

	if (!book_size)
	{
		std::cout << "PHONE BOOK IS EMPTY, ADD ALMOST ONE CONTACT" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << std::left << "INDEX" << "|"
			  << std::setw(10) << std::left << "FIRST NAME" << "|"
			  << std::setw(10) << std::left << "LAST NAME" << "|"
			  << std::setw(10) << std::left << "NICKNAME" << "|" << std::endl;
	std::cout << "____________________________________________" << std::endl;
	for (int i = 0; i < book_size - 1; i++)
	{
		std::cout << std::left << std::setw(10) << i + 1 << '|';
		printParams(book[i].getName(), book[i].getName().length());
		printParams(book[i].getSurname(), book[i].getSurname().length());
		printParams(book[i].getNickname(), book[i].getNickname().length());
		std::cout << std::endl;
	}
	std::cout << "____________________________________________" << std::endl;
	std::cout << "SELECT AN INDEX TO SHOW CONTACT'S INFORMATIONS" << std::endl;
	std::getline(std::cin, input);
	try
	{
		showContactInformations(std::stoi(input) - 1);
	} catch (...) {
		std::cout << "INDEX OUT OF BOUND" << std::endl;
	}
}

void	PhoneBook::showContactInformations(int index) {
	Contact c;

	if (index >= 0 && index < book_size - 1)
	{
		c = book[index];
		std::cout << "FIRST NAME: " << c.getName() << std::endl;
		std::cout << "LAST NAME: " << c.getSurname() << std::endl;
		std::cout << "NICKNAME: " << c.getNickname() << std::endl;
		std::cout << "LOGIN: " << c.getLogin() << std::endl;
		std::cout << "POSTAL ADDRESS: " << c.getPostalCode() << std::endl;
		std::cout << "EMAIL ADDRESS: " << c.getEmail() << std::endl;
		std::cout << "PHONE: " << c.getPhone() << std::endl;
		std::cout << "BIRTHDAY DATE: " << c.getBirthday() << std::endl;
		std::cout << "FAVORITE MEAL: " << c.getMeal() << std::endl;
		std::cout << "UNDERWEAR COLOR: " << c.getUnderwear() << std::endl;
		std::cout << "DARKEST SECRET: " << c.getSecret() << std::endl;
		return ;
	}
	throw 500;
}
