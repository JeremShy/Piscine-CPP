#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include <string>
# include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon & weapon);

private:
	std::string	_name;
	Weapon			*_weapon;
};

#endif
