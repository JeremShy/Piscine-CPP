#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap(60, 60, 120, 120, 1, "default name", 60, 5, 0) {
	std::cout << "NINJ4-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

NinjaTrap::NinjaTrap(std::string const name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0) {
	std::cout << "NINJ4-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src._hitPoints, src._mHitPoints, src._energyPoints, src._mEnergyPoints, src._level, src._name, src._meleeAttackDamage, src._rangedAttackDamage, src._armorDamageReduction) {
 std::cout << "NINJ4-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << ". I have been cloned !" << std::endl;
}

NinjaTrap::~NinjaTrap(void) {
 std::cout << this->_name << ": I officially declare the ninja i am dead." << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
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

void	NinjaTrap::rangedAttack(std::string const & target) const {
	std::cout << "NINJ4-TP, the invisible ninja bot, also named " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target) const {
	std::cout << "NINJ4-TP, the invisible ninja bot, also named " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap & trap) {
	std::cout << this->_name << ": Hides behind a shoebox and slowly crawls in the direction of NinjaTrap " << trap.getName() << "." << std::endl;
}

void	NinjaTrap::ninjaShoeBox(FragTrap & trap) {
	std::cout << this->_name << ": Launches a shoebox at FragTrap " << trap.getName() << "." << std::endl;
}

void	NinjaTrap::ninjaShoeBox(ScavTrap & trap) {
	std::cout << this->_name << ": Takes a donut out of the shoebox and shares it with ScavTrap " << trap.getName() << "." << std::endl;
}

void	NinjaTrap::ninjaShoeBox(ClapTrap & trap) {
	std::cout << this->_name << ": Tries to annoy ClapTrap " << trap.getName() << " by blinding him with a shoebox.";
}
