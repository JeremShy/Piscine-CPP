#ifndef OFFICE_BLOCK_CLASS_H
# define OFFICE_BLOCK_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock {
public:
	OfficeBlock(void);
	OfficeBlock(Intern *, Bureaucrat *, Bureaucrat *);
	~OfficeBlock(void);

	void	doBureaucracy(std::string form_name, std::string target) const;
	void	setIntern(Intern *intern);
	void	setSigner(Bureaucrat *sign);
	void	setExecutor(Bureaucrat *exec);

	Intern	*getIntern(void) const;
	Bureaucrat	*getSigner(void) const;
	Bureaucrat	*getExecutor(void) const;
private:
	OfficeBlock(OfficeBlock const & src);
	OfficeBlock & operator=(OfficeBlock const & rhs);

	Intern			*_intern;
	Bureaucrat	*_sign;
	Bureaucrat	*_exec;

public:

	class	SigningException : public std::exception {
	public:
		SigningException(void) throw();
		SigningException(SigningException const & src) throw();
		~SigningException(void) throw();
		SigningException & operator=(SigningException const & rhs) throw();
		virtual const char*	what() const throw();
	};

	class	ExecutingException : public std::exception {
	public:
		ExecutingException(void) throw();
		ExecutingException(ExecutingException const & src) throw();
		~ExecutingException(void) throw();
		ExecutingException & operator=(ExecutingException const & rhs) throw();
		virtual const char*	what() const throw();
	};

	class	CreationException : public std::exception {
	public:
		CreationException(void) throw();
		CreationException(CreationException const & src) throw();
		~CreationException(void) throw();
		CreationException & operator=(CreationException const & rhs) throw();
		virtual const char*	what() const throw();
	};

};
#endif
