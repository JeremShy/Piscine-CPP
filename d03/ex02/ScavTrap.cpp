#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap(void) : ClapTrap(100, 100, 50, 50, 1, "default name", 20, 15, 3) {
	std::cout << "SC4V-TP : Let's get this party started! Designation: " << this->_name << "." << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3) {

	std::cout << "SC4V-TP : Let's get this party started! Designation: " << this->_name << "." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src._hitPoints, src._mHitPoints, src._energyPoints, src._mEnergyPoints, src._level, src._name, src._meleeAttackDamage, src._rangedAttackDamage, src._armorDamageReduction)
{
 std::cout << "SC4V-TP : Let's get this party started! Designation: " << this->_name << ". I have been cloned !" << std::endl;
}

ScavTrap::~ScavTrap(void) {
 std::cout << this->_name << ": Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	this->_hitPoints = rhs._hitPoints;
	this->_mHitPoints = rhs._mHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_mEnergyPoints = rhs._mEnergyPoints;
	this->_level = rhs._level;
	this->_name = rhs. _name;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;

	return *this;
}

void	ScavTrap::rangedAttack(std::string const & target) const {
	std::cout << "SC4V-TP " << this->_name << " makes an awesome attack at " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) const {
	std::cout << "SC4V-TP " << this->_name << " makes a great attack at " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void	ScavTrap::cnChallenge1(std::string const &target) {
	std::cout << "You, " << target << ", will have to bring me the second horn of the pink unicorn !" << std::endl;
}
void	ScavTrap::cnChallenge2(std::string const &target) {
	std::cout << "You, " << target << ", will have to play the storm song with a rusty ocarina, while dancing the polka one on foot !" << std::endl;
}
void	ScavTrap::cnChallenge3(std::string const &target) {
	std::cout << "You, " << target << ", will have to give me $500,000. That's all." << std::endl;
}
void	ScavTrap::cnChallenge4(std::string const &target) {
	std::cout << "You, " << target << ", will have to sing the Fifth Element's song." << std::endl;
}
void	ScavTrap::cnChallenge5(std::string const &target) {
	std::cout << "You, " << target << ", will have to go and bring a megaphone to Zaz, and ask him to give you his Rainbow Dash's plush. This is the hardest challenge, tough luck ! Get rekt :)" << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {
	void(ScavTrap::*tab[5]) (std::string const &) = {&ScavTrap::cnChallenge1, &ScavTrap::cnChallenge2, &ScavTrap::cnChallenge3, &ScavTrap::cnChallenge4, &ScavTrap::cnChallenge5};;
	std::cout << this->_name << ": You... Newcomer... Here is my awesome and absolutely fabulous challenge !" << std::endl;
	(this->*(tab[rand() % 5]))(target);
}
