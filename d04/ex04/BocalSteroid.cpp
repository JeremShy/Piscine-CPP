#include "BocalSteroid.hpp"

BocalSteroid::BocalSteroid(void) {

}

BocalSteroid::BocalSteroid(std::string const & name) : _name(name) {

}

BocalSteroid::BocalSteroid(BocalSteroid const & src) : _name(src._name){

}

BocalSteroid::~BocalSteroid(void) {

}

BocalSteroid & BocalSteroid::operator=(BocalSteroid const & rhs) {
	this->_name = rhs._name;
	return (*this);
}

std::string BocalSteroid::beMined(DeepCoreMiner *) const {
	return ("Zazium");
}

std::string BocalSteroid::beMined(StripMiner *) const {
	return ("Krpite");
}

std::string BocalSteroid::getName(void) const {
	return (this->_name);
}
