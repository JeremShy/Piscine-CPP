#ifndef PEON_CLASS_H
# define PEON_CLASS_H

# include <string>
# include <iostream>
# include "Victim.hpp"

class Peon : public Victim {
public:
	Peon(Peon const & src);
	Peon(std::string const name);
	~Peon(void);

	Peon & operator=(Peon const & rhs);

	void	getPolymorphed() const;

private:
	Peon(void);
};
#endif
