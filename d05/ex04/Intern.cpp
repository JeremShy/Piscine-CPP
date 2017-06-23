#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {

}

Intern::Intern(Intern const &) {
}

Intern::~Intern(void) {

}

Intern & Intern::operator=(Intern const &) {
	return (*this);
}

Form	*Intern::makeForm(std::string const & f_name, std::string const & target) {
	Form *f;

	if (f_name == "presidential pardon") {
		f = new PresidentialPardonForm(target);
	}
	else if (f_name == "robotomy request") {
		f = new RobotomyRequestForm(target);
	}
	else if (f_name == "shrubbery creation") {
		f = new ShrubberyCreationForm(target);
	}
	else {
		throw Intern::InvalidFormNameException();
	}
	std::cout << "Intern creates " << *f << std::endl;
	return (f);
}

Intern::InvalidFormNameException::InvalidFormNameException(void) throw(){
}

Intern::InvalidFormNameException::InvalidFormNameException(Intern::InvalidFormNameException const &) throw(){
}

Intern::InvalidFormNameException::~InvalidFormNameException(void) throw(){
}

Intern::InvalidFormNameException & Intern::InvalidFormNameException::operator=(Intern::InvalidFormNameException const &) throw(){
	return (*this);
}

const char* Intern::InvalidFormNameException::what(void) const throw() {
	return ("invalid form name");
}
