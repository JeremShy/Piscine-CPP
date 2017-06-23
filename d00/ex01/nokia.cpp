#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int main() {

	Account list[8];
	std::string str;
	int					i;
	bool				cont;

	i = 0;

	(void)list;
	std::cout << "$> ";
	while (getline(std::cin, str)) {
		if (str == "ADD") {
			if (i >= 8) {
				std::cout << "There are already 8 contacts, you can't add contacts anymore !" << std::endl;
			}
			else {
				std::cout << "Adding contact number " << i + 1 << "." << std::endl;
				list[i].get_contact_info(i);
				i++;
			}
		}
		else if (str == "EXIT") {
			return (0);
		}
		else if (str == "SEARCH") {
			if (i == 0) {
				std::cout << "You must add contacts in the list before performing a search." << std::endl;
			}
			else {
				int j = 0;
				int	asked = 0;
				std::cout << std::right << std::setw(10) << "Index"
																	 << "|" << std::right << std::setw(10) << "First name"
																	 << "|" << std::right << std::setw(10) << "Last name"
																	 << "|" << std::right << std::setw(10) << "Nickname" << std::endl;
				while (!(list[j].get_empty()) && j < 8) {
					std::cout << std::right << std::setw(10) << list[j].get_index()
																		 << "|" << std::right << std::setw(10) << list[j].get_first_name()
																		 << "|" << std::right << std::setw(10) << list[j].get_last_name()
																		 << "|" << std::right << std::setw(10) << list[j].get_nickname() << std::endl;
					j++;
				}
				std::cout << "Please enter an index : ";
				cont = false;
				while (cont == false) {
					getline(std::cin, str);
					std::string::iterator it;
					it = str.begin();
					cont = (it == str.end() ? false : true);
					if (cont == false)
						std::cout << "Please enter a VALID index... : ";
					while (it != str.end() && cont == true) {
						if (*it < '0' || *it > '9' || str.length() == 0) {
							std::cout << "Please enter a VALID index... : ";
							cont = false;
						}
						it++;
					}
					asked = atoi(str.c_str());
					if (cont and (asked > 8 || asked > i - 1)) {
						std::cout << "The index you entered is either greater than 8 or lower than 8 but not yet entered." << std::endl;
						std::cout << "Please enter a VALID index... : ";
						cont = false;
					}
				}
				list[asked].print_info();
			}
		}
		std::cout << "$> ";
	}
}
