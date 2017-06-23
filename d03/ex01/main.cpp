#include <iostream>
#include <iomanip>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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

	ScavTrap st("Twilight Sparkle");
	st.rangedAttack("Apple Jack");
	st.meleeAttack("Apple Jack");
	st.takeDamage(2);
	st.takeDamage(10);
	st.takeDamage(10000);
	st.takeDamage(6);
	st.beRepaired(10);
	st.beRepaired(100);
	for (int i = 0; i < 5; i++) {st.challengeNewcomer("Apple Jack");}
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;

}
