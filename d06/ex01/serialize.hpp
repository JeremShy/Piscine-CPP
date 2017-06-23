#ifndef SERIALIZE_CLASS_H
# define SERIALIZE_CLASS_H

#include <string>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void	*serialize(void);
Data	*unserialize(void *raw);


#endif
