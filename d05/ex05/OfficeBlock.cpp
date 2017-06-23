#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : _intern(NULL), _sign(NULL), _exec(NULL){

}

OfficeBlock::OfficeBlock(Intern *inter, Bureaucrat *sign, Bureaucrat *exec) : _intern(inter), _sign(sign), _exec(exec) {

}

OfficeBlock::~OfficeBlock(void) {

}

void	OfficeBlock::setIntern(Intern *intern) {
	this->_intern = intern;
}
void	OfficeBlock::setSigner(Bureaucrat *sign) {
	this->_sign = sign;
}
void	OfficeBlock::setExecutor(Bureaucrat *exec) {
	this->_exec = exec;
}

Intern	*OfficeBlock::getIntern(void) const {
	return this->_intern;
}
Bureaucrat	*OfficeBlock::getSigner(void) const {
	return this->_sign;
}
Bureaucrat	*OfficeBlock::getExecutor(void) const {
	return this->_exec;
}

void	OfficeBlock::doBureaucracy(std::string form, std::string target) const {
	Form *f;
	try {
		f = (this->_intern)->makeForm(form, target);
	}
	catch (Intern::InvalidFormNameException & e) {
		throw (OfficeBlock::CreationException());
	}
	try {
		(this->_sign)->signForm(*f);
	} catch (std::exception & e) {
		free(f);
		throw (OfficeBlock::SigningException());
	}
	try {
		(this->_exec)->executeForm(*f);
	} catch (std::exception & e) {
		free(f);
		throw(OfficeBlock::ExecutingException());
	}
}

OfficeBlock::CreationException::CreationException(void) throw(){
}
OfficeBlock::CreationException::CreationException(OfficeBlock::CreationException const &) throw(){
}
OfficeBlock::CreationException::~CreationException(void) throw(){
}
OfficeBlock::CreationException & OfficeBlock::CreationException::operator=(OfficeBlock::CreationException const &) throw(){
	return (*this);
}
const char* OfficeBlock::CreationException::what(void) const throw() {
	return ("creation exception");
}


OfficeBlock::SigningException::SigningException(void) throw(){
}
OfficeBlock::SigningException::SigningException(OfficeBlock::SigningException const &) throw(){
}
OfficeBlock::SigningException::~SigningException(void) throw(){
}
OfficeBlock::SigningException & OfficeBlock::SigningException::operator=(OfficeBlock::SigningException const &) throw(){
	return (*this);
}
const char* OfficeBlock::SigningException::what(void) const throw() {
	return ("signing exception");
}


OfficeBlock::ExecutingException::ExecutingException(void) throw(){
}
OfficeBlock::ExecutingException::ExecutingException(OfficeBlock::ExecutingException const &) throw(){
}
OfficeBlock::ExecutingException::~ExecutingException(void) throw(){
}
OfficeBlock::ExecutingException & OfficeBlock::ExecutingException::operator=(OfficeBlock::ExecutingException const &) throw(){
	return (*this);
}
const char* OfficeBlock::ExecutingException::what(void) const throw() {
	return ("cxecuting exception");
}
