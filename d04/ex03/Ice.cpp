#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(Ice const & src) : AMateria(src) {
}

Ice::~Ice(void) {
}

Ice & Ice::operator=(Ice const & rhs) {
	this->AMateria::operator =(rhs);
	return (*this);
}

AMateria* Ice::clone() const {
	Ice *materia = new Ice();
	materia->setXP(this->getXP());
	return (materia);
}

void Ice::use(ICharacter& target) {
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
