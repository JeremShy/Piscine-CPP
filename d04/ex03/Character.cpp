#include "Character.hpp"



Character::Character(void) {

}

Character::Character(Character const & src) : _name(src._name), _amount(src._amount) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character::~Character(void) {
	for (unsigned int i = 0; i < this->_amount; i++) {
		delete this->_inventory[i];
	}
}

Character::Character(std::string const & name) : _name(name), _amount(0){

}

Character & Character::operator=(Character const & rhs) {
	this->~Character();
	_name = rhs._name;
	_amount = rhs._amount;
	for (unsigned int i = 0; i < this->_amount; i++) {
		this->_inventory[i] = rhs._inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m or this->_amount == 4)
		return ;
	this->_inventory[this->_amount] = m;
	this->_amount++;
}

void Character::unequip(int idx) {
	if ((unsigned int)idx >= this->_amount)
		return ;
	if ((unsigned int)idx == this->_amount - 1)
	{
		this->_amount--;
		return;
	}
	for (unsigned int i = (unsigned int)idx + 1; i < this->_amount; i++) {
		this->_inventory[i - 1] = this->_inventory[i];
	}
	this->_amount--;
}

void Character::use(int idx, ICharacter& target) {
	if ((unsigned int)idx >= this->_amount)
		return;
	this->_inventory[idx]->use(target);
}

void	Character::describe_inventory() const {
	std::cout << "-----------------------" << std::endl << this->_name << "'s inventory:" << std::endl;

	for (unsigned int i = 0; i < this->_amount; i++) {
		std::cout <<"[" << i << "]: " << this->_inventory[i]->getType() << std::endl;
	}

	std::cout << std::endl;
}
