#ifndef MINING_BARGE_CLASS_H
# define MINING_BARGE_CLASS_H

#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
	public:
		MiningBarge(void);
		MiningBarge(MiningBarge const & src);
		~MiningBarge(void);

		MiningBarge & operator=(MiningBarge const & rhs);

		void equip(IMiningLaser*);
		void mine(IAsteroid*) const;

	private:
		IMiningLaser* _arsenal[4];
		int						_amount;
};

#endif
