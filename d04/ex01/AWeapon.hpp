#ifndef AWEAPON_CLASS_H
# define AWEAPON_CLASS_H

# include <string>
# include <iostream>

class AWeapon {
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	virtual ~AWeapon();

	std::string const getName() const;
	int getAPCost() const;
	int getDamage() const;

	virtual void attack() const = 0;
	virtual AWeapon *clone() const = 0;
	AWeapon & operator=(AWeapon const & rhs);

protected:
	AWeapon(void);
	std::string	_name;
	int _apCost;
	int _damage;
};
#endif
