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

	class	InvalidFormNameException : public std::exception {
	public:
		InvalidFormNameException(void) throw();
		InvalidFormNameException(InvalidFormNameException const & src) throw();
		~InvalidFormNameException(void) throw();

		InvalidFormNameException & operator=(InvalidFormNameException const & rhs) throw();

		virtual const char*	what() const throw();
	};

private:
};

#endif
