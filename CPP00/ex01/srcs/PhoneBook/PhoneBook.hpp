//
// Created by Federico François on 20/05/21.
//

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../Contact/Contact.hpp"
#include <iostream>

class PhoneBook {
public:
	PhoneBook();
	void		start( void );

private:
	Contact		book[8];
	int 		book_size;
	void 		insertInfo( void );
	void		addContact( Contact contact );
	Contact 	*getBook( void );
	void		searchContact( void );
	void 		contacts_list( void );
	void 		terminate( void );
	void		printParams(std::string str, int toPrint);
	void		showContactInformations(int);
};

#endif //CPP0_PHONEBOOK_HPP
