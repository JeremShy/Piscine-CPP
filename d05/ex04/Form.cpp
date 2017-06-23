#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default Form"), _gradeRequiredSign(1), _gradeRequiredExec(1), _target("Default target"), _signed(false) {
}

Form::Form(Form const & src) : _name(src._name), _gradeRequiredSign(src._gradeRequiredSign), _gradeRequiredExec(src._gradeRequiredExec), _target(src._target), _signed(false) {
	if (src._gradeRequiredExec > 150 or src._gradeRequiredSign > 150)
		throw(GradeTooLowException());
	else if (src._gradeRequiredExec < 1 or src._gradeRequiredSign < 1)
		throw(GradeTooHighException());
}

Form::Form(std::string const & name, int gradeRequiredSign, int gradeRequiredExec, std::string const & target) : _name(name), _gradeRequiredSign(gradeRequiredSign), _gradeRequiredExec(gradeRequiredExec), _target(target), _signed(false){
	if (gradeRequiredExec > 150 or gradeRequiredSign > 150)
		throw(GradeTooLowException());
	else if (gradeRequiredExec < 1 or gradeRequiredSign < 1)
		throw(GradeTooHighException());
}

Form::~Form(void) {
}

Form & Form::operator=(Form const &) {
	return (*this);
}

void								Form::BeSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->_gradeRequiredSign) {
		throw (Form::GradeTooLowException());
	}
	else
		this->_signed = true;
}

void								Form::execute(Bureaucrat const &b) const{
	if (!this->_signed) {
		throw (Form::FormNotSignedException());
	}
	else if (b.getGrade() > this->_gradeRequiredExec) {
		throw (Form::GradeTooLowException());
	}
	this->doExecute(b);
}

std::ostream& operator<<(std::ostream& os, const Form & rhs) {
	os << rhs.getName() << " Form (s.grade " << rhs.getGradeRequiredSign() << ", ex.grade " << rhs.getGradeRequiredExec() << ") targeted on " << rhs.getTarget() << (rhs.getSigned() ? " (Signed)" : " (Unsigned)");
	return (os);
}



Form::GradeTooHighException::GradeTooHighException(void) throw(){
}

Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const &) throw(){
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(Form::GradeTooHighException const &) throw(){
	return (*this);
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Form - Grade too high.");
}

Form::GradeTooLowException::GradeTooLowException(void) throw(){
}

Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const &) throw(){
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(Form::GradeTooLowException const &) throw(){
	return (*this);
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Form - Grade too low.");
}

Form::FormNotSignedException::FormNotSignedException(void) throw(){
}

Form::FormNotSignedException::FormNotSignedException(Form::FormNotSignedException const &) throw(){
}

Form::FormNotSignedException::~FormNotSignedException(void) throw(){
}

Form::FormNotSignedException & Form::FormNotSignedException::operator=(Form::FormNotSignedException const &) throw(){
	return (*this);
}

const char* Form::FormNotSignedException::what(void) const throw() {
	return ("Form - Form not signed.");
}

unsigned int	Form::getGradeRequiredExec(void) const {
	return (this->_gradeRequiredExec);
}

unsigned int	Form::getGradeRequiredSign(void) const {
	return (this->_gradeRequiredSign);
}

std::string	Form::getName(void) const {
	return (this->_name);
}

std::string	Form::getTarget(void) const {
	return (this->_target);
}


bool				Form::getSigned(void) const {
	return (this->_signed);
}
