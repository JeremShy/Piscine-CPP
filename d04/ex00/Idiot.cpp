#include "Idiot.hpp"

Idiot::Idiot(void) {
}

Idiot::Idiot(Idiot const & src) : Victim(src){

}

Idiot::~Idiot(void) {
	std::cout << "The idiot is dead. Long live the idiot !" << std::endl;
}

Idiot::Idiot(std::string const name) : Victim(name) {
	std::cout << "Wut ? I am not very intelligent !" << std::endl;
}

void	Idiot::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a green monkey !" << std::endl;
}

Idiot & Idiot::operator=(Idiot const & rhs) {
	this->_name = rhs._name;

	return (*this);
}
