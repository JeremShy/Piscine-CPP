#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(Cure const & src) : AMateria(src) {
}

Cure::~Cure(void) {
}

Cure & Cure::operator=(Cure const & rhs) {
	this->AMateria::operator =(rhs);
	return (*this);
}

AMateria* Cure::clone() const {
	Cure *materia = new Cure();
	materia->setXP(this->getXP());
	return (materia);
}

void Cure::use(ICharacter& target) {
	this->AMateria::use(target);
	std::cout << "*  heals " << target.getName() << "'s wounds *" << std::endl;
}
