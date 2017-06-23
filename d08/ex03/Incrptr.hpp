#ifndef INCRPTR_CLASS_H
# define INCRPTR_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Incrptr : public AInstruction {
public:
	Incrptr(void);
	Incrptr(Incrptr const & src);
	~Incrptr(void);

	Incrptr & operator=(Incrptr const & rhs);

	void execute();
private:
};
#endif
