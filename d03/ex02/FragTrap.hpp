#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string const name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	vaulthunter_dot_exe(std::string const & target);

private:
	FragTrap(void);
	void	vhClapInTheBox(std::string const & target);
	void	vhGunWizard(std::string const & target);
	void	vhTorgueFiesta(std::string const & target);
	void	vhPirateShipMode(std::string const & target);
	void	vhLaserInferno(std::string const & target);

};
#endif
