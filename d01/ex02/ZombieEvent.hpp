#ifndef ZOMBIE_EVENT_CLASS_H
# define ZOMBIE_EVENT_CLASS_H

# include <string>
# include "Zombie.hpp"

class ZombieEvent {
public:
	ZombieEvent(void);
	ZombieEvent(std::string type);
	~ZombieEvent(void);

	void setZombieType(std::string type);
	Zombie *newZombie(std::string name);
	void	randomChump(void);

private:
	std::string		_type;
};

#endif
