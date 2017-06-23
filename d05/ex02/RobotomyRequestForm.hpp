#ifndef ROBOTOMY_REQUEST_FORM_CLASS_H
# define ROBOTOMY_REQUEST_FORM_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string const & target);

	~RobotomyRequestForm(void);

private:
	RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	void	doExecute(Bureaucrat const & executor) const;
};
#endif
