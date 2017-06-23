#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <string>
# include <iostream>

class Bureaucrat;
std::ostream& operator<<(std::ostream& os, const Bureaucrat & rhs);

class Form {
public:
	Form(std::string const & name, int gradeRequiredSign, int gradeRequiredExec, std::string const & target);
	Form(Form const & src);
	virtual ~Form(void);

	unsigned int	getGradeRequiredSign(void) const;
	unsigned int	getGradeRequiredExec(void) const;
	std::string 	getName(void) const;
	std::string 	getTarget(void) const;
	bool					getSigned(void) const;

	void								BeSigned(const Bureaucrat &b);
	void								execute(const Bureaucrat &b) const;

	class	GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const & src) throw();
		~GradeTooHighException(void) throw();

		GradeTooHighException & operator=(GradeTooHighException const & rhs) throw();

		virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const & src) throw();
		~GradeTooLowException(void) throw();

		GradeTooLowException & operator=(GradeTooLowException const & rhs) throw();

		virtual const char*	what() const throw();
	};

	class	FormNotSignedException : public std::exception {
	public:
		FormNotSignedException(void) throw();
		FormNotSignedException(FormNotSignedException const & src) throw();
		~FormNotSignedException(void) throw();

		FormNotSignedException & operator=(FormNotSignedException const & rhs) throw();

		virtual const char*	what() const throw();
	};

private:
	Form(void);
	Form & operator=(Form const & rhs);

	virtual void	doExecute(Bureaucrat const & executor) const = 0;

	std::string const		_name;
	unsigned int const	_gradeRequiredSign;
	unsigned int const	_gradeRequiredExec;
	std::string const		_target;
	bool								_signed;
};

std::ostream& operator<<(std::ostream& os, const Form & rhs);

#endif
