#include "Character.hpp"

Character::Character(void) {
}

Character::Character(std::string const & name) : _ap(40), _name(name), _weapon(NULL){
}

Character::Character(Character const & src) : _ap(src._ap), _name(src._name), _weapon(src._weapon->clone()){
}

Character::~Character(void) {
	// Je ne suis pas certain de si il est necessaire ou pas de supprimer l'arme actuelle du perso, car risque de double free si le main la supprime egalement. Du coup je mets quand meme ce commentaire pour prouver que j'y ai pensé. :D.
	if (this->_weapon)
		delete this->_weapon;
}

Character & Character::operator=(Character const & rhs) {
	this->_ap = rhs._ap;
	this->_name = rhs._name;
	this->_weapon = rhs._weapon->clone();
	return *this;
}

void Character::recoverAP() {
	if (this->_ap == 40)
		return ;
	this->_ap += 10;
	if (this->_ap > 40)
		this->_ap = 40;
}

void Character::equip(AWeapon* arme) {
	this->_weapon = arme;
}

void Character::attack(Enemy* mechant) {
	if 	(!(this->_weapon) || !mechant)
		return ;
	if (this->_ap >= (this->_weapon)->getAPCost()) {
		this->_ap -= (this->_weapon)->getAPCost();
		std::cout << this->_name << " attacks " << mechant->getType() << " with a " << (this->_weapon)->getName() << std::endl;
		this->_weapon->attack();
		mechant->takeDamage(this->_weapon->getDamage());
		if (mechant->getHP() <= 0) {
			std::cout << mechant->getType() << " is dead and will now be deleted. You would better not try to attack him again or you will probably segfault. Just sayin'." << std::endl;
			delete mechant; //Tout nouvel appel à cette fonction avec le meme enemy en argument occasionnera un comportement indéterminé.  Il aurait été mieux de faire que Character::attack renvoie un booleen pour dire au main() que l'ennemi est mort et désormais invalide..
		}
	}
}

std::string const Character::getName() const {
	return (this->_name);
}

AWeapon	*Character::getWeapon() const {
	return (this->_weapon);
}

int	Character::getAp() const {
	return (this->_ap);
}

std::ostream &	operator<<(std::ostream & o, Character const & i) {
	if (i.getWeapon()) {
		o << i.getName() << " has " << i.getAp() << " AP and wields a " << (i.getWeapon())->getName() << std::endl;
	}
	else {
		o << i.getName() << " has " << i.getAp() << " AP and is unarmed" << std::endl;
	}
	return (o);
}
