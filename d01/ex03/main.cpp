#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int main() {
	ZombieHorde a(2);
	a.announce();
	std::cout << std::endl;

	ZombieHorde b(10);
	b.announce();
	std::cout << std::endl;

	ZombieHorde c(50);
	c.announce();

	return (0);
}
