#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character(Character const & src);
	Character(std::string const & name);
	~Character(void);

	Character & operator=(Character const & rhs);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	void	describe_inventory() const;
private:
	Character(void);

	std::string _name;
	AMateria *_inventory[4];
	unsigned int _amount;
};

#endif
