#include "Array.template.hpp"

int main() {
	Array<int> a(4);

	int &x = a[0];

	x = 21;
	a[1] = 2;
	a[2] = 4;
	a[3] = 42;

	for (unsigned int i = 0; i < a.size() ; i++) {
		std::cout << "[" << i << "] : " << a[i] << std::endl;
	}

	std::cout << std::endl;

	Array<int> b(a);

	b[2] = 8;

	std::cout << "A:" << std::endl;

	for (unsigned int i = 0; i < a.size() ; i++) {
		std::cout << "[" << i << "] : " << a[i] << std::endl;
	}

	std::cout << "B:" << std::endl;

	for (unsigned int i = 0; i < b.size() ; i++) {
		std::cout << "[" << i << "] : " << b[i] << std::endl;
	}


	try {
		std::cout << "a[4] : " << a[4] << std::endl;
	} catch (std::exception & e) {
		std::cout << "Error ! Exception caught : " << e.what() << std::endl;
	}

	try {
		std::cout << "a[-1] : " << a[-1] << std::endl;
	} catch (std::exception & e) {
		std::cout << "Error ! Exception caught : " << e.what() << std::endl;
	}

}
