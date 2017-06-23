#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : FragTrap() {
	this->_energyPoints = 120;
	this->_mEnergyPoints = 120;
	this->_meleeAttackDamage = 60;
	std::cout << "SUP3R-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

SuperTrap::SuperTrap(std::string const & name) : FragTrap(name) {
	this->_energyPoints = 120;
	this->_mEnergyPoints = 120;
	this->_meleeAttackDamage = 60;
	this->_name = name;
	std::cout << "SUP3R-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << name << "." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src._hitPoints, src._mHitPoints, src._energyPoints, src._mEnergyPoints, src._level, src._name, src._meleeAttackDamage, src._rangedAttackDamage, src._armorDamageReduction) {
 std::cout << "SUP3R-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << ". I have been cloned !" << std::endl;
}

SuperTrap::~SuperTrap(void) {
 std::cout << this->_name << ": I officially declare the super bot i am dead." << std::endl;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs) {
	this->_hitPoints = rhs._hitPoints;
	this->_mHitPoints = rhs._mHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_mEnergyPoints = rhs._mEnergyPoints;
	this->_level = rhs._level;
	this->_name = rhs._name;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;

	return *this;
}

void	SuperTrap::rangedAttack(std::string const & target) const {
	this->FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target) const {
	this->NinjaTrap::meleeAttack(target);
}
