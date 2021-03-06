#ifndef BOUCLE_FIN_CLASS_H
# define BOUCLE_FIN_CLASS_H

#include "mindopen.hpp"

class BoucleFin : public AInstruction {
public:
	BoucleFin(void);
	BoucleFin(BoucleFin const & src);
	~BoucleFin(void);

	BoucleFin & operator=(BoucleFin const & rhs);

	void execute();
private:
};
#endif
