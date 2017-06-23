#ifndef IMINING_LASER_CLASS_H
# define IMINING_LASER_CLASS_H

# include "IAsteroid.hpp"

class IMiningLaser
{
	public:
		virtual ~IMiningLaser() {}
		virtual void mine(IAsteroid*) = 0;
		virtual			IMiningLaser *clone(void) = 0;
};

#endif
