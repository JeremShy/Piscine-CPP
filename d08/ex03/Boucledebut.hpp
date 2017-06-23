#ifndef BOUCLE_DEBUT_CLASS_H
# define BOUCLE_DEBUT_CLASS_H

#include "mindopen.hpp"

class BoucleDebut : public AInstruction {
public:
	BoucleDebut(void);
	BoucleDebut(BoucleDebut const & src);
	~BoucleDebut(void);

	BoucleDebut & operator=(BoucleDebut const & rhs);

	void execute();
private:
};
#endif
