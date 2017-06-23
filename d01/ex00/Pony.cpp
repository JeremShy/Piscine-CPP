#include "Pony.hpp"
#include <iostream>

Pony::Pony() : _name("default_name"),
							 _mane_color(0x000000),
							 _fur_color(0xEEFFEE),
							 _winged(false),
							 _unicorn(false)
{
			std::cout << "Creating a new pony with a default name." << std::endl;
}

Pony::Pony(std::string name) : _name(name),
							 _mane_color(0x000000),
							 _fur_color(0xEEFFEE),
							 _winged(false),
							 _unicorn(false)
{
			std::cout << "Creating a new pony named \"" << name << "\"." << std::endl;
}


Pony::~Pony() {
	std::cout << "Deleting a pony named \"" << this->_name << "\"." << std::endl;
}

void Pony::walk(int distance) {
	std::cout << this->_name << " walked " << distance << " meters." << std::endl;
}

void Pony::talk(std::string str) {
	std::cout << "-" << this->_name << ": " << str << std::endl;
}
