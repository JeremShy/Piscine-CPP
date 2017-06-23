#ifndef SQUAD_CLASS_H
# define SQUAD_CLASS_H

# include <string>
# include <iostream>
# include "ISquad.hpp"

class Squad : public ISquad {
public:
	Squad(void);
	Squad(Squad const & src);
	~Squad(void);

	Squad & operator=(Squad const & rhs);

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);

private:
	int	_count;
	ISpaceMarine**	_squad;
};
#endif
