#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include <string>
# include <iostream>

class FragTrap {
public:
	FragTrap(std::string const name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	FragTrap & operator=(FragTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);

private:
	FragTrap(void);
	void	vhClapInTheBox(std::string const & target);
	void	vhGunWizard(std::string const & target);
	void	vhTorgueFiesta(std::string const & target);
	void	vhPirateShipMode(std::string const & target);
	void	vhLaserInferno(std::string const & target);

	int					_hitPoints;
	int					_mHitPoints;
	int					_energyPoints;
	int					_mEnergyPoints;
	int					_level;
	std::string	_name;
	int					_meleeAttackDamage;
	int					_rangedAttackDamage;
	int					_armorDamageReduction;

};
#endif
