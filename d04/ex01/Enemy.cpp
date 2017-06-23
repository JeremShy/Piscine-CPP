#include "Enemy.hpp"

Enemy::Enemy(void) {
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type){

}

Enemy::Enemy(Enemy const & src) : _hp(src._hp), _type(src._type) {

}

Enemy::~Enemy(void) {

}

Enemy & Enemy::operator=(Enemy const & rhs) {
	this->_hp = rhs._hp;
	this->_type = rhs._type;

	return *(this);
}

std::string const Enemy::getType() const {
	return this->_type;
}

int	Enemy::getHP(void) const {
	return (this->_hp);
}

void Enemy::takeDamage(int damage) {
	if (damage < 0)
		return ;
	this->_hp -= damage;
	return ;
}
