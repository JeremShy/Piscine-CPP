#ifndef DECROCT_CLASS_H
# define DECROCT_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Decroct : public AInstruction {
public:
	Decroct(void);
	Decroct(Decroct const & src);
	~Decroct(void);

	Decroct & operator=(Decroct const & rhs);

	void execute();
private:
};
#endif
