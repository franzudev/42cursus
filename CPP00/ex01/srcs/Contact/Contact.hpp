#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

struct ContactInfo {
	std::string name;
	std::string surname;
	std::string nickname;
	std::string login;
	std::string postal_code;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string meal;
	std::string underwear;
	std::string secret;
};

class Contact {
	public:
		Contact();
		Contact(ContactInfo);
		~Contact( void );
		std::string	getName( void );
		void		setName(std::string str);
		std::string	getSurname( void );
		void		setSurname(std::string str);
		std::string	getNickname( void );
		void		setNickname(std::string str);
		std::string	getLogin( void );
		void		setLogin(std::string str);
		std::string	getPostalCode( void );
		void		setPostalCode(std::string str);
		std::string	getEmail( void );
		void		setEmail(std::string str);
		std::string	getPhone( void );
		void		setPhone(std::string str);
		std::string	getBirthday( void );
		void		setBirthday(std::string str);
		std::string	getMeal( void );
		void		setMeal(std::string str);
		std::string	getUnderwear( void );
		void		setUnderwear(std::string str);
		std::string	getSecret( void );
		void		setSecret(std::string str);
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string login;
		std::string	postal_code;
		std::string	email;
		std::string	phone;
		std::string	birthday;
		std::string	meal;
		std::string	underwear;
		std::string	secret;

};
#endif
