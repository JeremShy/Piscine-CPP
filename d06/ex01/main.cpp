#include "serialize.hpp"
#include <iostream>

int main() {
	void *addr = serialize();

	char	*t1 = reinterpret_cast<char*>(addr);
	int		*n = reinterpret_cast<int*>(reinterpret_cast<char*>(addr) + sizeof(char) * 8);
	char	*t2 = reinterpret_cast<char*>(reinterpret_cast<char*>(addr) + sizeof(char) * 8 + sizeof(int));

	std::cout << "First tab : ";
	for (int i = 0; i < 8; i++)
		std::cout << t1[i];
	std::cout << std::endl;

	std::cout << "Random number : " << *n << std::endl;

	std::cout << "Second tab : ";
	for (int i = 0; i < 8; i++)
		std::cout << t2[i];
	std::cout << std::endl;

	std::cout << "/////////////////////////////////////////////////" << std::endl;

	Data *data = unserialize(addr);

	std::cout << "In data : " << std::endl << "s1: " << data->s1 << std::endl
		<< "n: " << data->n << std::endl
		<< "s2: " << data->s2 << std::endl;

	delete data;
	operator delete(addr);

	return (0);
}
