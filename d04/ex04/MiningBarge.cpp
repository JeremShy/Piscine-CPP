#include "MiningBarge.hpp"

MiningBarge::MiningBarge(void) : _amount(0){
}

MiningBarge::MiningBarge(MiningBarge const & src) : _amount(src._amount) {
	for (int i = 0; i < this->_amount; i++) {
		this->_arsenal[i] = src._arsenal[i]->clone();
	}
}

MiningBarge::~MiningBarge(void) {
	for (int i = 0; i < this->_amount; i++) {
		delete this->_arsenal[i];
	}
}

MiningBarge & MiningBarge::operator=(MiningBarge const & rhs) {
	this->~MiningBarge();
	this->_amount = rhs._amount;
	for (int i = 0; i < this->_amount; i++) {
		this->_arsenal[i] = rhs._arsenal[i]->clone();
	}
	return (*this);
}

void MiningBarge::equip(IMiningLaser* laser) {
	if (this->_amount == 4 || !laser)
		return ;
	this->_arsenal[this->_amount] = laser;
	this->_amount++;
}

void MiningBarge::mine(IAsteroid* target) const {
	for (int i = 0; i < this->_amount; i++) {
		this->_arsenal[i]->mine(target);
	}
}
