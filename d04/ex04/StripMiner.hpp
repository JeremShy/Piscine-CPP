#ifndef STRIP_MINER_CLASS_H
# define STRIP_MINER_CLASS_H

# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser {
public:
	StripMiner(void);
	StripMiner(StripMiner const & src);
	~StripMiner(void);

	StripMiner & operator=(StripMiner const & rhs);

	void mine(IAsteroid*);

	IMiningLaser *clone(void);
private:
};

#endif
