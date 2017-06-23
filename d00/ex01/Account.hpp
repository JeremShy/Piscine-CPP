#ifndef ACCOUNT_CLASS_H
# define ACCOUNT_CLASS_H

#include <string>

class Account {
public:
	Account(void);
	~Account(void);

	void				get_contact_info(int index);

	bool				get_empty(void) const;
	int					get_index(void) const;
	void				print_info(void) const;
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
private:
	bool _empty;

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_address;
	std::string _email_address;
	std::string _phone_number;
	std::string _birthday_date;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;

	int					_index;
};

#endif
