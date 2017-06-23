#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void) : _type("default_type"){
	std::string name[10] = {"Tim", "Bob", "Jim", "Marvin", "Gabe", "Rainbow Dash", "Come", "Maxime", "Jeremy", "Marine Le Pen"};
	this->setName(name[std::rand() % 10]);
	std::cout << "Creating a zombie named \"" << this->_name << "\"." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Deleting the zombie named \"" << this->_name << "\" and with type \"" << this->_type << "\"." << std::endl;
}

void Zombie::announce(void) {
	std::cout << "<" << this->_name << " (" << this->_type << ")> Poniiiiieeeeeessss..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}
