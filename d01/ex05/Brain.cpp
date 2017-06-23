#include "Brain.hpp"
#include <string>
#include <sstream>
#include <iostream>

Brain::Brain(void) :	_lobe_frontal("Ceci est le lobe frontal."),
											_lobe_temporal("Ceci est le lobe temporal."),
											_lobe_parietal("Ceci est le lobe parietal."),
											_lobe_occipital("Ceci est le lobe occipital."),
											_cervelet("Ceci est le cervelet."),
											_scissure_sylvius("Ceci est la scissure de Sylvius.")
{
}

Brain::~Brain(void) {

}

std::string Brain::identify(void) const{

	std::stringstream s;

	s << this;
	return (s.str());
}
