#ifndef SUPERTRAP_CLASS_H
# define SUPERTRAP_CLASS_H

# include <string>
# include <iostream>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
	SuperTrap(std::string const & name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap(void);

	SuperTrap & operator=(SuperTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;

private:
	SuperTrap(void);

};
#endif
