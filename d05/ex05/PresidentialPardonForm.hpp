#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_H
# define PRESIDENTIAL_PARDON_FORM_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string const & target);

	~PresidentialPardonForm(void);

private:
	PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	void	doExecute(Bureaucrat const & executor) const;

};
#endif
