#ifndef PLASMA_RIFLE_CLASS_H
# define PLASMA_RIFLE_CLASS_H

# include <string>
# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon{
public:
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const & src);
	~PlasmaRifle();

	void attack() const;
	PlasmaRifle & operator=(PlasmaRifle const & rhs);

	AWeapon *clone() const;
};

#endif
