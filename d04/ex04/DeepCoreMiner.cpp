#include <iostream>
#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void) {
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &) {
}

DeepCoreMiner::~DeepCoreMiner(void) {
}

DeepCoreMiner & DeepCoreMiner::operator=(DeepCoreMiner const &) {
	return (*this);
}

void DeepCoreMiner::mine(IAsteroid *target) {
	std::cout << "* mining deep ... got " << target->beMined(this) << " ! *" << std::endl;
}

IMiningLaser *DeepCoreMiner::clone(void) {
	return (new DeepCoreMiner);
}
