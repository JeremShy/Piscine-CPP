#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);

	ScavTrap & operator=(ScavTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	challengeNewcomer(std::string const & target);

private:
	ScavTrap(void);
	void	cnChallenge1(std::string const &target);
	void	cnChallenge2(std::string const &target);
	void	cnChallenge3(std::string const &target);
	void	cnChallenge4(std::string const &target);
	void	cnChallenge5(std::string const &target);

};
#endif
