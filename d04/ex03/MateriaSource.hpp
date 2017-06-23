#ifndef MATERIA_SOURCE_CLASS_H
# define MATERIA_SOURCE_CLASS_H

# include <string>
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);

	MateriaSource & operator=(MateriaSource const & rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	AMateria* _inventory[4];
	int _amount;
};

#endif
