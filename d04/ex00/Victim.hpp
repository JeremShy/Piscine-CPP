#ifndef VICTIM_CLASS_H
# define VICTIM_CLASS_H

# include <string>
# include <iostream>

class Victim {
public:
	Victim(Victim const & src);
	Victim(std::string const name);
	virtual ~Victim(void);

	Victim & operator=(Victim const & rhs);

	virtual void	getPolymorphed() const;

	std::string getName() const;

protected:
	std::string	_name;
	Victim(void);

};

std::ostream &	operator<<(std::ostream & o, Victim const & i);
#endif
