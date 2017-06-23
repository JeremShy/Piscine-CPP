#ifndef OUTOCT_CLASS_H
# define OUTOCT_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Outoct : public AInstruction {
public:
	Outoct(void);
	Outoct(Outoct const & src);
	~Outoct(void);

	Outoct & operator=(Outoct const & rhs);

	void execute();
private:
};
#endif
