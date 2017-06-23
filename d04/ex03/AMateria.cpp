#include "AMateria.hpp"

AMateria::AMateria(void) : xp_(0) {

}

AMateria::AMateria(AMateria const & src) : xp_(src.xp_), _type(src._type){

}

AMateria::~AMateria(void) {
}

AMateria & AMateria::operator=(AMateria const & rhs) {
	this->xp_ = rhs.xp_;
	this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const {
	return (this->_type);
}

unsigned int AMateria::getXP() const {
	return (this->xp_);
}

void AMateria::setXP(unsigned int xp) {
	this->xp_ = xp;
}

AMateria::AMateria(std::string const & type) : xp_(0), _type(type){
}

void AMateria::use(ICharacter&) {
	this->xp_ += 10;
}
