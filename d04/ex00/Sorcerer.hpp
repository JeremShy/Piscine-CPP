#ifndef SORCERER_CLASS_H
# define SORCERER_CLASS_H

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer {
public:
	Sorcerer(Sorcerer const & src);
	Sorcerer(std::string const name, std::string const title);
	~Sorcerer(void);

	Sorcerer & operator=(Sorcerer const & rhs);

	void polymorph(Victim const & v) const;

	std::string getName() const;
	std::string getTitle() const;

private:
	Sorcerer(void);

	std::string	_name;
	std::string	_title;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & i);
#endif
