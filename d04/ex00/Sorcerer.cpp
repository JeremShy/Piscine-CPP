#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) {
}

Sorcerer::Sorcerer(Sorcerer const & src) : _name(src._name), _title(src._title){
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(std::string const name, std::string const title) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

std::string	Sorcerer::getName(void) const {
	return (this->_name);
}

std::string	Sorcerer::getTitle(void) const {
	return (this->_title);
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
	this->_name = rhs._name;
	this->_title = rhs._title;

	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & i) {
	o << "I am " << i.getName() << ", " << i.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

void Sorcerer::polymorph(Victim const & v) const {
	v.getPolymorphed();
}
