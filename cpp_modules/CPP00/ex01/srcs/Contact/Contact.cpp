#include "Contact.hpp"

Contact::Contact() {
}

Contact::Contact(ContactInfo info)
{
	setName(info.name);
	setSurname(info.surname);
	setNickname(info.nickname);
	setLogin(info.login);
	setPostalCode(info.postal_code);
	setEmail(info.email);
	setPhone(info.phone);
	setBirthday(info.birthday);
	setMeal(info.meal);
	setUnderwear(info.underwear);
	setSecret(info.secret);
}

Contact::~Contact()
{
}

std::string	Contact::getName(void)
{
	return name;
}

std::string	Contact::getSurname(void)
{
	return surname;
}

std::string	Contact::getNickname(void)
{
	return nickname;
}

void	Contact::setName(std::string nameVal)
{
	name = nameVal;
}

void	Contact::setSurname(std::string surnameVal)
{
	surname = surnameVal;
}

void	Contact::setNickname(std::string nicknameVal)
{
	nickname = nicknameVal;
}

std::string Contact::getLogin(void) {
	return login;
}

void Contact::setLogin(std::string str) {
	login = str;
}

std::string Contact::getPostalCode(void) {
	return postal_code;
}

void Contact::setPostalCode(std::string str) {
	postal_code = str;
}

std::string Contact::getEmail(void) {
	return email;
}

void Contact::setEmail(std::string str) {
	email = str;
}

std::string Contact::getPhone(void) {
	return phone;
}

void Contact::setPhone(std::string str) {
	phone = str;
}

std::string Contact::getBirthday() {
	return birthday;
}

void Contact::setBirthday(std::string str) {
	birthday = str;
}

std::string Contact::getMeal(void) {
	return meal;
}

void Contact::setMeal(std::string str) {
	meal = str;
}

std::string Contact::getUnderwear(void) {
	return underwear;
}

void Contact::setUnderwear(std::string str) {
	underwear = str;
}

std::string Contact::getSecret(void) {
	return secret;
}

void Contact::setSecret(std::string str) {
	secret = str;
}

