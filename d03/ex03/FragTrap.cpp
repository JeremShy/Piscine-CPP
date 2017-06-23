#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <ctime>

FragTrap::FragTrap(void) : ClapTrap(100, 100, 100, 100, 1, "default name", 30, 20, 5) {
	std::cout << "FR4G-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5) {

	std::cout << "FR4G-TP : Booting sequence complete. Hello! I am your new steward bot. Designation: " << this->_name << "." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src._hitPoints, src._mHitPoints, src._energyPoints, src._mEnergyPoints, src._level, src._name, src._meleeAttackDamage, src._rangedAttackDamage, src._armorDamageReduction)
{
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
