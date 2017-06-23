#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"

class Intern {
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern & operator=(Intern const & rhs);

	Form	*makeForm(std::string const &	f_name, std::string const & target);


private:
};

#endif
