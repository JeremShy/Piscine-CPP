#ifndef RAD_SCORPION_CLASS_H
# define RAD_SCORPION_CLASS_H

#include <iostream>
#include <string>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const & src);
		~RadScorpion();
		RadScorpion & operator=(RadScorpion const & rhs);

	private:
};
#endif
