#ifndef TACTICAL_MARINE_CLASS_H
# define TACTICAL_MARINE_CLASS_H

# include <string>
# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);
	~TacticalMarine(void);

	TacticalMarine & operator=(TacticalMarine const & rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
