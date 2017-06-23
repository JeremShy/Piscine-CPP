#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
	int i;
	std::string str("");
	const char	*s;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < ac) {
		str += av[i];
		i++;
	}
	s = str.c_str();
	i = 0;
	while (s[i]) {
		std::cout << (char)toupper(s[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
