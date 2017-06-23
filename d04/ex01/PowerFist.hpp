#ifndef POWER_FIST_CLASS_H
# define POWER_FIST_CLASS_H

# include <string>
# include <iostream>
# include "AWeapon.hpp"

class PowerFist : public AWeapon{
public:
	PowerFist(void);
	PowerFist(PowerFist const & src);
	~PowerFist();

	void attack() const;
	PowerFist & operator=(PowerFist const & rhs);
	AWeapon *clone() const;
};

#endif
