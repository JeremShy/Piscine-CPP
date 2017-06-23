#ifndef ASTERO_BOCAL_CLASS_H
# define ASTERO_BOCAL_CLASS_H

# include <string>
# include <iostream>
# include "IAsteroid.hpp"

class AsteroBocal : public IAsteroid {
public:
	AsteroBocal(std::string const &name);
	AsteroBocal(AsteroBocal const & src);
	~AsteroBocal(void);

	AsteroBocal & operator=(AsteroBocal const & rhs);

	std::string beMined(DeepCoreMiner *) const;
	std::string beMined(StripMiner *) const;
	std::string getName() const;

private:
	AsteroBocal(void);

	std::string	_name;
};

#endif
