#include <iostream>
#include "Account.hpp"

Account::Account(void) : _empty(true) {
}

Account::~Account(void) {
}

void Account::get_contact_info(int index) {
	this->_empty = false;
	this->_index = index;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_login = "";
	this->_postal_address = "";
	this->_email_address = "";
	this->_phone_number = "";
	this->_birthday_date = "";
	this->_favorite_meal = "";
	this->_underwear_color = "";
	this->_darkest_secret = "";

	while (this->_first_name == "") {
		std::cout << "First name: ";
		getline(std::cin, this->_first_name);
	}

	while (this->_last_name == "") {
		std::cout << "Last name: ";
		getline(std::cin, this->_last_name);
	}

	while (this->_nickname == "") {
		std::cout << "Nickname: ";
		getline(std::cin, this->_nickname);
	}

	while (this->_login == "") {
		std::cout << "Login: ";
		getline(std::cin, this->_login);
	}

	while (this->_postal_address == "") {
		std::cout << "Postal address: ";
		getline(std::cin, this->_postal_address);
	}

	while (this->_email_address == "") {
		std::cout << "Email address: ";
		getline(std::cin, this->_email_address);
	}

	while (this->_phone_number == "") {
		std::cout << "Phone number: ";
		getline(std::cin, this->_phone_number);
	}

	while (this->_birthday_date == "") {
		std::cout << "Birthday date: ";
		getline(std::cin, this->_birthday_date);
	}

	while (this->_favorite_meal == "") {
		std::cout << "Favorite meal: ";
		getline(std::cin, this->_favorite_meal);
	}

	while (this->_underwear_color == "") {
		std::cout << "Underwear color: ";
		getline(std::cin, this->_underwear_color);
	}

	while (this->_darkest_secret == "") {
		std::cout << "Darkest secret: ";
		getline(std::cin, this->_darkest_secret);
	}
}


bool Account::get_empty(void) const{
	return this->_empty;
}

std::string	Account::get_first_name(void) const{
	if (this->_first_name.length() > 10) {
		std::string ret = this->_first_name.substr(0, 9);
		ret += ".";
		return ret;
	}
	return this->_first_name;
}

std::string	Account::get_last_name(void) const{
	if (this->_last_name.length() > 10) {
		std::string ret = this->_last_name.substr(0, 9);
		ret += ".";
		return ret;
	}
	return this->_last_name;
}

std::string	Account::get_nickname(void) const{
	if (this->_nickname.length() > 10) {
		std::string ret = this->_nickname.substr(0, 9);
		ret += ".";
		return ret;
	}
	return this->_nickname;
}

int Account::get_index(void) const{
	return this->_index;
}

void Account::print_info(void) const {

	std::cout << "First name : "      << this->_first_name      << std::endl;
	std::cout << "Last name : "       << this->_last_name       << std::endl;
	std::cout << "Nickname : "        << this->_nickname        << std::endl;
	std::cout << "Login : "           << this->_login           << std::endl;
	std::cout << "Postal Address : "  << this->_postal_address  << std::endl;
	std::cout << "Email Address : "   << this->_email_address   << std::endl;
	std::cout << "Phone Number : "    << this->_phone_number    << std::endl;
	std::cout << "Birthday Date : "   << this->_birthday_date   << std::endl;
	std::cout << "Favorite Meal : "   << this->_favorite_meal   << std::endl;
	std::cout << "Underwear Color : " << this->_underwear_color << std::endl;
	std::cout << "Darkest Secret : "  << this->_darkest_secret  << std::endl;

}
