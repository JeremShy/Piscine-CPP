#ifndef INOCT_CLASS_H
# define INOCT_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Inoct : public AInstruction {
public:
	Inoct(void);
	Inoct(Inoct const & src);
	~Inoct(void);

	Inoct & operator=(Inoct const & rhs);

	void execute();
private:
};
#endif
