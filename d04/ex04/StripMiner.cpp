#include <iostream>
#include "StripMiner.hpp"

StripMiner::StripMiner(void) {
}

StripMiner::StripMiner(StripMiner const &) {
}

StripMiner::~StripMiner(void) {
}

StripMiner & StripMiner::operator=(StripMiner const &) {
	return (*this);
}

void StripMiner::mine(IAsteroid *target) {
	std::cout << "* strip mining ... got " << target->beMined(this) << " ! *" << std::endl;
}

IMiningLaser *StripMiner::clone(void) {
	return (new StripMiner);
}
