#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default Form"), _gradeRequiredSign(1), _gradeRequiredExec(1), _signed(false) {
}

Form::Form(Form const & src) : _name(src._name), _gradeRequiredSign(src._gradeRequiredSign), _gradeRequiredExec(src._gradeRequiredExec), _signed(false) {
	if (src._gradeRequiredExec > 150 or src._gradeRequiredSign > 150)
		throw(GradeTooLowException());
	else if (src._gradeRequiredExec < 1 or src._gradeRequiredSign < 1)
		throw(GradeTooHighException());
}

Form::Form(std::string name, int gradeRequiredExec, int gradeRequiredSign) : _name(name), _gradeRequiredSign(gradeRequiredSign), _gradeRequiredExec(gradeRequiredExec), _signed(false){
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

void								Form::BeExecuted(Bureaucrat const &b) {
	if (b.getGrade() > this->_gradeRequiredExec) {
		throw (Form::GradeTooLowException());
	}
	else
		this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form & rhs) {
	os << "[" << rhs.getName() << "]" << "-FORM: grade to sign :  " << rhs.getGradeRequiredSign() << " / grade to exec : " << rhs.getGradeRequiredExec() << " / signed : " << rhs.getSigned();
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


unsigned int	Form::getGradeRequiredExec(void) const {
	return (this->_gradeRequiredExec);
}

unsigned int	Form::getGradeRequiredSign(void) const {
	return (this->_gradeRequiredSign);
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool				Form::getSigned(void) const {
	return (this->_signed);
}
