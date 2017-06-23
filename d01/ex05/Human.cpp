# include <string>
# include "Brain.hpp"
# include "Human.hpp"
# include <iostream>

Human::Human(void) : _brain(Brain()) {

}

Human::~Human(void) {

}

std::string Human::identify(void) const{
	return (_brain).identify();
}

Brain const & Human::getBrain(void) const {
	return (_brain);
}
