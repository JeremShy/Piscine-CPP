#ifndef BOCAL_STEROID_CLASS_H
# define BOCAL_STEROID_CLASS_H

# include <string>
# include <iostream>
# include "IAsteroid.hpp"

class BocalSteroid : public IAsteroid {
public:
	BocalSteroid(std::string const &name);
	BocalSteroid(BocalSteroid const & src);
	~BocalSteroid(void);

	BocalSteroid & operator=(BocalSteroid const & rhs);

	std::string beMined(DeepCoreMiner *) const;
	std::string beMined(StripMiner *) const;
	std::string getName() const;

private:
	BocalSteroid(void);

	std::string	_name;
};

#endif
