#ifndef EASYFIND_CLASS_H
# define EASYFIND_CLASS_H

# include <string>
# include <iostream>

template<typename T>
typename T::iterator	easyfind(T cont, int val) {
	typename T::iterator it;

	it = find(cont.begin(), cont.end(), val);
	if (it != cont.end()) {
		return (it);
	} else {
		throw std::range_error("The specified value could not be found");
	}
}

#endif
