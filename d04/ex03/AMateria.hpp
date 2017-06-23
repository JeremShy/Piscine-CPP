#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria {
	public:
		AMateria(void);
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria & operator=(AMateria const & rhs);
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		void	setXP(unsigned int amount); //Returns the Materia's XP
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	private:
		unsigned int xp_;
		std::string _type;
};

#endif
