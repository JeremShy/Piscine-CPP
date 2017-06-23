#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>
# include <iostream>

class ClapTrap {
public:
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const & src);
	ClapTrap(int hitPoints, int mHitPoints, int energyPoints, int mEnergyPoints, int level, std::string const & name, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const & rhs);

	void	rangedAttack(std::string const & target) const;
	void	meleeAttack(std::string const & target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string const &	getName() const;

protected:
	int					_hitPoints;
	int					_mHitPoints;
	int					_energyPoints;
	int					_mEnergyPoints;
	int					_level;
	std::string	_name;
	int					_meleeAttackDamage;
	int					_rangedAttackDamage;
	int					_armorDamageReduction;

private:
	ClapTrap(void);


};
#endif
