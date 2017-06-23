#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: Please enter exactly 3 parameters." << std::endl;
		return (1);
	}
	std::string filename = std::string(av[1]), s1 = std::string(av[2]), s2 = std::string(av[3]);

	if (filename.length() == 0 or s1.length() == 0 or s2.length() == 0) {
		std::cerr << "Error: You specified at least one empty parameter. Please stop trying to break me. It hurts. :(" << std::endl;
		return (1);
	}

	std::fstream input(filename, std::fstream::in);
	if (!input.is_open()) {
		std::cerr << "Error: Error opening " << filename << " for reading." << std::endl;
		return (1);
	}

	std::fstream output(filename + ".replace", std::fstream::out | std::fstream::trunc);
	if (!output.is_open()) {
		input.close();
		std::cerr << "Error: Error opening " << filename << ".replace for writing." << std::endl;
		return (1);
	}

	std::string	str;
	std::stringstream ss;
	size_t			res;

	ss << input.rdbuf();
	str = ss.str();
	res = 0;
	while ((res = str.find(s1)) != std::string::npos) {
		str.erase(res, s1.length());
		str.insert(res, s2);
	}
	output << str;
	input.close();
	output.close();
	return (0);
}
