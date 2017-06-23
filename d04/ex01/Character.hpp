#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		Character(void);
		int	_ap;
		std::string	_name;
		AWeapon	*_weapon;

	public:
		Character(std::string const & name);
		Character(Character const & src);
		Character & operator=(Character const & rhs);
		~Character();

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const getName() const;
		AWeapon	*getWeapon() const;
		int	getAp() const;
};

std::ostream &	operator<<(std::ostream & o, Character const & i);
#endif
