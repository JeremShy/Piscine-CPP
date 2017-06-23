#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

class Brain {
public:
	Brain(void);
	~Brain(void);

std::string	identify(void) const;

private:
	std::string	_lobe_frontal;
	std::string	_lobe_temporal;
	std::string	_lobe_parietal;
	std::string	_lobe_occipital;
	std::string	_cervelet;
	std::string	_scissure_sylvius;
};

#endif
