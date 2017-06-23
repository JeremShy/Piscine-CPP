#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Presidential Pardon", 25, 5, "Default target"){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : Form(src.getName(), src.getGradeRequiredSign(), src.getGradeRequiredExec(), src.getTarget()){
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("Presidential Pardon", 25, 5, target) {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &) {
	return (*this);
}

void											PresidentialPardonForm::doExecute(Bureaucrat const & executor) const {
	std::cout << *this << " about to be executed by " << executor << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
