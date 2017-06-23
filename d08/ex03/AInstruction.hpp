#ifndef AINSTRUCTION_CLASS_H
# define AINSTRUCTION_CLASS_H

# include <string>
# include <iostream>

class AInstruction {
public:
	AInstruction(void);
	AInstruction(AInstruction const & src);
	~AInstruction(void);

	virtual void execute() = 0;

	AInstruction & operator=(AInstruction const & rhs);

private:
	char	*ptr;
	char	*tab;
	int		*i;
};
#endif
