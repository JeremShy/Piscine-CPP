#ifndef SUPER_MUTANT_CLASS_H
# define SUPER_MUTANT_CLASS_H

#include <iostream>
#include <string>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const & src);
		~SuperMutant();
		SuperMutant & operator=(SuperMutant const & rhs);

		void takeDamage(int);

	private:
};

#endif
