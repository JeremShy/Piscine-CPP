#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void) : _name("default_name"), _type("default_type"){
	std::cout << "Creating a new zombie with default name and default type." << std::endl;
}

Zombie::Zombie(std::string type) : _name("default_name"), _type(type) {
	std::cout << "Creating a new zombie with default name and with type \"" << this->_type << "\"." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Deleting the zombie named \"" << this->_name << "\" and with type \"" << this->_type << "\"." << std::endl;
}

void Zombie::announce(void) {
	std::cout << "<" << this->_name << " (" << this->_type << ")> Poniiiiieeeeeessss..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
	std::cout << "Setting zombie's name to " << this->_name << std::endl;
}
