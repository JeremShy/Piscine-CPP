#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
	(void)src;
}

TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs) {
	(void)rhs;
	return (*this);
}

ISpaceMarine* TacticalMarine::clone() const {
	return (new TacticalMarine);
}
void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}
void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}
void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}
