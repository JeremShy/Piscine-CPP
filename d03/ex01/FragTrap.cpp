#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap(void) : _hitPoints(100),
													 _mHitPoints(100), _energyPoints(100),
													 _mEnergyPoints(100), _level(1), _name("Default name"),
													 _meleeAttackDamage(30), _rangedAttackDamage(20),
													 _armorDamageReduction(5) {
	std::cout << "FR4G-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

FragTrap::FragTrap(std::string const name) : _hitPoints(100), _mHitPoints(100), _energyPoints(100),
																						 _mEnergyPoints(100), _level(1), _name(name),
																						 _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5) {

	std::cout << "FR4G-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : _hitPoints(src._hitPoints), _mHitPoints(src._mHitPoints), _energyPoints(src._energyPoints),
																					 _mEnergyPoints(src._mEnergyPoints), _level(src._level), _name(src._name),
																					 _meleeAttackDamage(src._meleeAttackDamage), _rangedAttackDamage(src._rangedAttackDamage),
																					 _armorDamageReduction(src._armorDamageReduction) {
 std::cout << "FR4G-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << ". I have been cloned !" << std::endl;

}

FragTrap::~FragTrap(void) {
 std::cout << this->_name << ": I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
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

void	FragTrap::rangedAttack(std::string const & target) const {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}
void	FragTrap::takeDamage(unsigned int amount) {
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
void	FragTrap::beRepaired(unsigned int amount) {
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

void	FragTrap::vhClapInTheBox(std::string const & target) {
	std::cout << this->_name << ": Performing Clap In The Box attack on " << target << "." << std::endl;
}
void	FragTrap::vhGunWizard(std::string const & target) {
	std::cout << this->_name << ": Performing Gun Wizard attack on " << target << "." << std::endl;
}
void	FragTrap::vhTorgueFiesta(std::string const & target) {
	std::cout << this->_name << ": Performing Torgue Fiesta attack on " << target << "." << std::endl;
}
void	FragTrap::vhPirateShipMode(std::string const & target) {
	std::cout << this->_name << ": Performinging Pirate Ship Mode attack on " << target << "." << std::endl;
}
void	FragTrap::vhLaserInferno(std::string const & target) {
	std::cout << this->_name << ": Performing Laser Inferno attack on " << target << "." << std::endl;
}


void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energyPoints < 25) {
		std::cout << this->_name << ": I don't have enough  energy points to launch my super attack :(." << std::endl;
	}
	else {
		this->_energyPoints -= 25;
		std::cout << this->_name << ": This time it'll be awesome, I promise! But now i have only " << this->_energyPoints << " energy point(s) !" << std::endl;
		void(FragTrap::*tab[5]) (std::string const &) = {&FragTrap::vhClapInTheBox, &FragTrap::vhGunWizard, &FragTrap::vhTorgueFiesta, &FragTrap::vhPirateShipMode, &FragTrap::vhLaserInferno};
		(this->*(tab[rand() % 5]))(target);
	}
}
