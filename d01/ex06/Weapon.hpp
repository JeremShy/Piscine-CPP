#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <string>

class Weapon {
public:
	Weapon(std::string);
	~Weapon(void);

	const std::string & getType(void) const;
	void								setType(std::string s);
private:
	std::string	type;
};

#endif
