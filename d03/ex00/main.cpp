#include <iostream>
#include <iomanip>
#include "FragTrap.hpp"

int main() {
	FragTrap ft("Rainbow Dash");
	ft.rangedAttack("Fluttershy");
	ft.meleeAttack("Fluttershy");
	ft.takeDamage(2);
	ft.takeDamage(10);
	ft.takeDamage(10000);
	ft.takeDamage(6);
	ft.beRepaired(10);
	ft.beRepaired(100);
	for (int i = 0; i < 5; i++) {ft.vaulthunter_dot_exe("Fluttershy");}
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
}
