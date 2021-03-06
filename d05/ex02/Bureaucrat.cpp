#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const &name, int	grade) : _name(name) {
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {
	if (src._grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (src._grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	this->_grade = rhs._grade;

	return (*this);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

Bureaucrat & Bureaucrat::operator++(int) {
	if (this->_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
	return (*this);
}
Bureaucrat & Bureaucrat::operator--(int) {
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
	return (*this);
}

void					Bureaucrat::incGrade(void) {
	if (this->_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void					Bureaucrat::decGrade(void) {
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void					Bureaucrat::signForm(Form & f) const {
	try {
		f.BeSigned(*this);
		std::cout << "<" << *this << "> signed form <" << f << ">." << std::endl;
	} catch (Form::GradeTooLowException & e) {
		std::cout << "<" << *this << "> can't sign form <" << f << "> because his grade is too low." << std::endl;
		return ;
	}
}

void					Bureaucrat::executeForm(Form const & f) const {
	try {
		f.execute(*this);
		std::cout << "<" << *this << "> executes <" << f << ">." << std::endl;
	} catch (std::ios_base::failure & e) {
		std::cout << "<" << *this << "> couldn't execute form <" << f << "> because there was a problem while opening the file" << std::endl;
		return ;
	} catch (std::exception & e) {
		std::cout << "<" << *this << "> couldn't execute form <" << f << "> because of : " << e.what() << std::endl;
		return ;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat & rhs) {
	os << "[" << rhs.getName() << "]" << "-BUREAUCRAT: grade " << rhs.getGrade() << "";
	return (os);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw(){
}

Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat::GradeTooHighException const &) throw(){
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &) throw(){
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high.");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw(){
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const &) throw(){
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &) throw(){
	return (*this);
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low.");
}
