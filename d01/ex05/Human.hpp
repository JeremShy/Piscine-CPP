#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

# include <string>
# include "Brain.hpp"

class Human {
public:
	Human(void);
	~Human(void);

std::string identify(void) const;
Brain const & getBrain(void) const;

private:
	const Brain _brain;
};

#endif
