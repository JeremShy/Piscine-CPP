#ifndef DECRPTR_CLASS_H
# define DECRPTR_CLASS_H

# include <string>
# include <iostream>
# include "AInstruction.hpp"

class Decrptr : public AInstruction {
public:
	Decrptr(void);
	Decrptr(Decrptr const & src);
	~Decrptr(void);

	Decrptr & operator=(Decrptr const & rhs);

	void execute();
private:
};
#endif
