#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>
# include <iostream>
# include "Form.hpp"

class Bureaucrat {
public:
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat(std::string const &name, int	grade);

	~Bureaucrat(void);

	Bureaucrat & operator++(int);
	Bureaucrat & operator--(int);

	void					incGrade(void);
	void					decGrade(void);

	void					signForm(Form & f) const;
	void					executeForm(Form const & f) const;

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

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
	Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	const std::string		_name;
	unsigned int				_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & rhs);

#endif
