#include "Peon.hpp"

Peon::Peon(void) {
}

Peon::Peon(Peon const & src) : Victim(src){

}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(std::string const name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

void	Peon::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon const & rhs) {
	this->_name = rhs._name;

	return (*this);
}
