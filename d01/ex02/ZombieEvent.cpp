#include <iostream>
#include <string>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) : _type("default_type") {
	std::cout << "Creating a new default ZombieEvent." << std::endl;
}

ZombieEvent::ZombieEvent(std::string type) : _type(type) {
	std::cout << "Creating a new ZombieEvent with type \"" << this->_type << "\"." << std::endl;
}

ZombieEvent::~ZombieEvent() {
	std::cout << "Destroying a ZombieEvent with type \"" << this->_type << "\"." << std::endl;
}

void ZombieEvent::setZombieType(std::string type) {
	std::cout << "Setting type at \"" << type << "\"." << std::endl;
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) {
	std::cout << "Creating a zombie using the ZombieEvent::newZombie func." << std::endl;
	Zombie *a = new Zombie(this->_type);
	a->setName(name);
	return a;
}

void	ZombieEvent::randomChump(void) {
	std::string name[5] = {"Tim", "Bob", "Jim", "Marvin", "Gabe"};
	Zombie zombie(this->_type);
	zombie.setName(name[std::rand() % 5]);
	zombie.announce();
}
