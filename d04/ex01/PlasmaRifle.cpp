#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src){
}

PlasmaRifle::~PlasmaRifle() {
}


void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	AWeapon::operator =(rhs);
	return *this;
}

AWeapon *PlasmaRifle::clone(void) const {
	return new PlasmaRifle(*this);
}
