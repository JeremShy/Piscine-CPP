#include "ClapTrap.hpp"
#include <ctime>

ClapTrap::ClapTrap(void) : _hitPoints(100),
													 _mHitPoints(100), _energyPoints(100),
													 _mEnergyPoints(100), _level(1), _name("Default name"),
													 _meleeAttackDamage(30), _rangedAttackDamage(20),
													 _armorDamageReduction(5) {
	std::cout << "CL4P-TP : ClapTrap's general booting sequence for " << this->_name << " is complete !" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _hitPoints(100), _mHitPoints(100), _energyPoints(100),
																						 _mEnergyPoints(100), _level(1), _name(name),
																						 _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {

	std::cout << "CL4P-TP : ClapTrap's general booting sequence for " << this->_name << " is complete !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : _hitPoints(src._hitPoints), _mHitPoints(src._mHitPoints), _energyPoints(src._energyPoints),
																					 _mEnergyPoints(src._mEnergyPoints), _level(src._level), _name(src._name),
																					 _meleeAttackDamage(src._meleeAttackDamage), _rangedAttackDamage(src._rangedAttackDamage),
																					 _armorDamageReduction(src._armorDamageReduction) {
	std::cout << "CL4P-TP : ClapTrap's general booting sequence for " << this->_name << " is complete !" << std::endl;

}

ClapTrap::ClapTrap(	int hitPoints, int mHitPoints, int energyPoints, int mEnergyPoints, int level, std::string const &name,
										int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction) :
										_hitPoints(hitPoints), _mHitPoints(mHitPoints), _energyPoints(energyPoints),
										_mEnergyPoints(mEnergyPoints), _level(level), _name(name), _meleeAttackDamage(meleeAttackDamage),
										_rangedAttackDamage(rangedAttackDamage), _armorDamageReduction(armorDamageReduction) {
	std::cout << "CL4P-TP : ClapTrap's general booting sequence for " << this->_name << " is complete !" << std::endl;

}

ClapTrap::~ClapTrap(void) {
 std::cout << this->_name << ": Claptrap is now officially dead. How sad. :(." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
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

void	ClapTrap::takeDamage(unsigned int amount) {
	int dt;

	dt = amount - this->_armorDamageReduction;
	if (dt <= 0) {
		std::cout << this->_name << ": Ow hohoho, i haven't taken any damage!" << std::endl;
	}
	else {
		std::cout << this->_name << ": Ow hohoho, that hurts! Yipes! Supposed to take " << amount << " damage, but only taking " << dt << " damages thanks to my awesome armor!" << std::endl;
		if (dt >= this->_hitPoints) {
			std::cout << this->_name << ": I am supposed to die, but thanks to my awesome composition, i can't fall below 0 HP, and i survive when I have 0 HP ! Ain't that great ?" << std::endl;
			this->_hitPoints = 0;
		}
		else {
			this->_hitPoints -= dt;
			std::cout << this->_name << ": I now have only " << this->_hitPoints << " Hp. :(." << std:: endl;
		}
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << this->_name << ": I found health!" << std::endl;

	if (this->_hitPoints + (int)amount > this->_mHitPoints) {
		std::cout << this->_name << ": You lost some heal, buddy. I will just reset to my maximum health ! (" << this->_mHitPoints << ")" << std::endl;
		this->_hitPoints = this->_mHitPoints;
	}
	else {
		this->_hitPoints += amount;
		std::cout << this->_name << ": Thank you for the heal ! I now have " << this->_hitPoints << "HP." << std::endl;
	}
}
