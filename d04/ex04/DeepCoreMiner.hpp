#ifndef DEEP_CORE_MINER_CLASS_H
# define DEEP_CORE_MINER_CLASS_H

# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser {
public:
	DeepCoreMiner(void);
	DeepCoreMiner(DeepCoreMiner const & src);
	~DeepCoreMiner(void);

	DeepCoreMiner & operator=(DeepCoreMiner const & rhs);
	IMiningLaser *clone(void);

	void mine(IAsteroid*);

private:
};

#endif
