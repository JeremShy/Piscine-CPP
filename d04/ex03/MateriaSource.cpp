#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _amount(0){

}

MateriaSource::MateriaSource(MateriaSource const & src) : _amount(src._amount){
	for (int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < this->_amount; i++) {
		delete this->_inventory[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	this->~MateriaSource();
	this->_amount = rhs._amount;
	for (int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (this->_amount == 4)
		return ;
	this->_inventory[this->_amount] = materia->clone();
	(this->_amount)++;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_amount; i++) {
		if ((this->_inventory[i])->getType() == type) {
			return (this->_inventory[i])->clone();
		}
	}
	return (NULL);
}
