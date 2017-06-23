#include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> v;
	v.push_back(5);
	v.push_back(50);
	v.push_back(10);
	v.push_back(23);
	v.push_back(0);
	v.push_back(9);
	v.push_back(4);

	try {
		std::vector<int>::iterator it = easyfind<std::vector<int> >(v, 9);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	try {
		std::vector<int>::iterator it = easyfind<std::vector<int> >(v, 90);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
