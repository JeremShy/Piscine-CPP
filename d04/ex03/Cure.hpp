#ifndef CURE_CLASS_H
# define CURE_CLASS_H

# include <string>
# include <iostream>
# include "AMateria.hpp"


class Cure : public AMateria{

public:
	Cure(void);
	Cure(Cure const & src);
	~Cure(void);

	Cure & operator=(Cure const & rhs);

	AMateria* clone() const;
	void use(ICharacter& target);
private:
};
#endif
