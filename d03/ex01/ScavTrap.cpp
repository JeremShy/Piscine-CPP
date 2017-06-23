#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap(void) : _hitPoints(100),
													 _mHitPoints(100), _energyPoints(50),
													 _mEnergyPoints(50), _level(1), _name("Default name"),
													 _meleeAttackDamage(20), _rangedAttackDamage(15),
													 _armorDamageReduction(3) {
	std::cout << "SC4V-TP : Let's get this party started! Designation: " << this->_name << "." << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : _hitPoints(100), _mHitPoints(100), _energyPoints(50),
																						 _mEnergyPoints(50), _level(1), _name(name),
																						 _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3) {

	std::cout << "SC4V-TP : Let's get this party started! Designation: " << this->_name << "." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : _hitPoints(src._hitPoints), _mHitPoints(src._mHitPoints), _energyPoints(src._energyPoints),
																					 _mEnergyPoints(src._mEnergyPoints), _level(src._level), _name(src._name),
																					 _meleeAttackDamage(src._meleeAttackDamage), _rangedAttackDamage(src._rangedAttackDamage),
																					 _armorDamageReduction(src._armorDamageReduction) {
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
	this->_name = rhs._name;
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
void	ScavTrap::takeDamage(unsigned int amount) {
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
void	ScavTrap::beRepaired(unsigned int amount) {
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
	std::cout << "You... Newcomer... Here is my awesome and absolutely fabulous challenge !" << std::endl;
	(this->*(tab[rand() % 5]))(target);
}
