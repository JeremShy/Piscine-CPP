#include "Victim.hpp"

Victim::Victim(void) {
}

Victim::Victim(Victim const & src) : _name(src._name){
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason." << std::endl;
}

Victim::Victim(std::string const name) : _name(name) {
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

std::string	Victim::getName(void) const {
	return (this->_name);
}

void	Victim::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs) {
	this->_name = rhs._name;

	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Victim const & i) {
	o << "I'm " << i.getName() << " and I like otters !" << std::endl;
	return o;
}
