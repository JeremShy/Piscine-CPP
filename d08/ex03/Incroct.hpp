#ifndef INCROCT_CLASS_H
# define INCROCT_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Incroct : public AInstruction {
public:
	Incroct(void);
	Incroct(Incroct const & src);
	~Incroct(void);

	Incroct & operator=(Incroct const & rhs);

	void execute();
private:
};
#endif
