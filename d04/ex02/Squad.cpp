#include "Squad.hpp"

Squad::Squad(void) : _squad(NULL){
}

Squad::Squad(Squad const & src) {
	this->_squad = new ISpaceMarine*[src._count];
	for (int i = 0; i < src._count ; i++) {
		this->_squad[i] = (src._squad[i])->clone();
	}
	this->_count = src._count;
}

Squad::~Squad(void) {
	for (int i = 0; i < this->_count ; i++) {
		delete this->_squad[i];
	}
	delete [] this->_squad;
}

Squad & Squad::operator=(Squad const & rhs) {
	Squad::~Squad();
	this->_squad = new ISpaceMarine*[rhs._count];
	for (int i = 0; i < rhs._count ; i++) {
		this->_squad[i] = (rhs._squad[i])->clone();
	}
	this->_count = rhs._count;

	return (*this);
}

int Squad::getCount() const {
	return (this->_count);
}

ISpaceMarine* Squad::getUnit(int n) const {
	if (n < this->_count)
		return (this->_squad[n]);
	return (NULL);
}
int Squad::push(ISpaceMarine* elem) {
	if (!elem)
		return this->_count;

	for (int i = 0; i < this->_count; i++) {
		if (this->_squad[i] == elem) {
			return this->_count;
		}
	}

	if (!this->_squad) {
		this->_count = 1;
		this->_squad = new ISpaceMarine*[this->_count];
		this->_squad[0] = elem;
		return (1);
	}
	else {
		ISpaceMarine **nsquad = new ISpaceMarine*[this->_count + 1];
		for (int i = 0; i < this->_count ; i++) {
			nsquad[i] = this->_squad[i];
		}
		nsquad[this->_count] = elem;
		delete [] this->_squad;
		this->_squad = nsquad;
		this->_count++;
		return (this->_count);
	}
}
