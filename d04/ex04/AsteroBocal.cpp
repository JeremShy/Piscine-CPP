#include "AsteroBocal.hpp"

AsteroBocal::AsteroBocal(void) {

}

AsteroBocal::AsteroBocal(std::string const & name) : _name(name) {

}

AsteroBocal::AsteroBocal(AsteroBocal const & src) : _name(src._name){

}

AsteroBocal::~AsteroBocal(void) {

}

AsteroBocal & AsteroBocal::operator=(AsteroBocal const & rhs) {
	this->_name = rhs._name;
	return (*this);
}

std::string AsteroBocal::beMined(DeepCoreMiner *) const {
	return ("Thorite");
}

std::string AsteroBocal::beMined(StripMiner *) const {
	return ("Flavium");
}

std::string AsteroBocal::getName(void) const {
	return (this->_name);
}
