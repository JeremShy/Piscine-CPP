#ifndef IDIOT_CLASS_H
# define IDIOT_CLASS_H

# include <string>
# include <iostream>
# include "Victim.hpp"

class Idiot : public Victim {
public:
	Idiot(Idiot const & src);
	Idiot(std::string const name);
	~Idiot(void);

	Idiot & operator=(Idiot const & rhs);

	void	getPolymorphed() const;

private:
	Idiot(void);
};
#endif
