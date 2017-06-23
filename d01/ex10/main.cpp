#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void	print_file_content(std::string const filename, char *name) {

	std::string tmp(name);
	std::ifstream fs(filename, std::ifstream::in);
	if (!fs.is_open()) {
		std::cerr << name << ": "<< filename << ": "<< strerror(errno) << std::endl;
		return ;
	}

	std::string	str;
	std::stringstream ss;

	ss << fs.rdbuf();
	str = ss.str();
	std::cout << ss.str();
	fs.close();
}

int main(int ac, char **av) {
	(void)av;
	if (ac == 1) {
		std::string str;
		while (std::getline(std::cin, str)) {
			std::cout << str << std::endl;
		}
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		if (strcmp(av[i], "-") == 0) {
			std::string str;
			while (std::getline(std::cin, str)) {
				std::cout << str << std::endl;
			}
		}
		else {
			print_file_content(av[i], av[0]);
		}
	}
	return (0);
}
