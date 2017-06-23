#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main() {
	ZombieEvent arm;
	ZombieEvent brain;

	arm.setZombieType("Arm eater");
	brain.setZombieType("Brain sucker");

	std::cout << std::endl << "Creating a new Arm Eater with newZombie." << std::endl;
	Zombie *a = arm.newZombie("Percy");
	a->announce();
	delete a;

	std::cout << std::endl << "Creating 10 random chumps with randomChump" << std::endl << std::endl;
	for (int i = 0 ; i < 10 ; i++) {
		brain.randomChump();
		std::cout << std::endl;
	}
	return (0);
}
