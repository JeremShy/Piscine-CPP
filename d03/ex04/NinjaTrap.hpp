#ifndef NinjaTrap_CLASS_H
# define NinjaTrap_CLASS_H

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {
public:
	NinjaTrap(std::string const name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);

	NinjaTrap & operator=(NinjaTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	ninjaShoeBox(NinjaTrap & trap);
	void	ninjaShoeBox(FragTrap & trap);
	void	ninjaShoeBox(ScavTrap & trap);
	void	ninjaShoeBox(ClapTrap & trap);

protected:
	NinjaTrap(void);
};
#endif
