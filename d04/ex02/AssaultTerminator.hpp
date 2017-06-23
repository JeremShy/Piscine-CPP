#ifndef ASSAULT_TERMINATOR_CLASS_H
# define ASSAULT_TERMINATOR_CLASS_H

# include <string>
# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const & src);
	~AssaultTerminator(void);

	AssaultTerminator & operator=(AssaultTerminator const & rhs);

	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
};

#endif
