#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class Zombie {
public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string type);

	void	announce(void);
	void	setName(std::string name);

private:
	std::string   _name;
	std::string		_type;
};

#endif
