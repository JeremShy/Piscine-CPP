#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {

}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src){
}

PowerFist::~PowerFist() {
}


void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs) {
	AWeapon::operator =(rhs);
	return *this;
}

AWeapon *PowerFist::clone() const {
	return new PowerFist(*this);
}
