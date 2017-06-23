#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <string>
# include <iostream>

class Bureaucrat;

class Form {
public:
	Form(std::string name, int gradeRequiredExec, int gradeRequiredSign);
	Form(Form const & src);
	~Form(void);

	unsigned int	getGradeRequiredSign(void) const;
	unsigned int	getGradeRequiredExec(void) const;
	std::string 	getName(void) const;
	bool					getSigned(void) const;

	void								BeSigned(const Bureaucrat &b);
	void								BeExecuted(const Bureaucrat &b);

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


private:
	Form(void);
	Form & operator=(Form const & rhs);

	std::string const		_name;
	unsigned int const	_gradeRequiredSign;
	unsigned int const	_gradeRequiredExec;
	bool								_signed;
};

std::ostream& operator<<(std::ostream& os, const Form & rhs);

#endif
