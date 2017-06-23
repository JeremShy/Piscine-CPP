#include <iostream>
#include <iomanip>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

	NinjaTrap nt("Pinkie Pie");
	nt.rangedAttack("Rarity");
	nt.meleeAttack("Rarity");
	nt.takeDamage(2);
	nt.takeDamage(10);
	nt.takeDamage(10000);
	nt.takeDamage(6);
	nt.beRepaired(10);
	nt.beRepaired(100);
	nt.ninjaShoeBox(ft);
	std::cout << std::endl;
	nt.ninjaShoeBox(st);
	std::cout << std::endl;
	nt.ninjaShoeBox(nt);
	std::cout << std::endl;
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;

	SuperTrap sut("Derpie hooves");
	sut.rangedAttack("Mark Zuckerberg");
	sut.meleeAttack("Mark Zuckerberg");
	sut.takeDamage(2);
	sut.takeDamage(10);
	sut.takeDamage(10000);
	sut.takeDamage(6);
	sut.beRepaired(10);
	sut.beRepaired(100);
	sut.ninjaShoeBox(ft);
	std::cout << std::endl;
	sut.ninjaShoeBox(st);
	std::cout << std::endl;
	sut.ninjaShoeBox(nt);
	std::cout << std::endl;
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
	for (int i = 0; i < 5; i++) {sut.vaulthunter_dot_exe("Fluttershy");}
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
}
