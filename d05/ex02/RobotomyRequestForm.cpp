#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Robotomy Request", 72, 45, "Default target"){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : Form(src.getName(), src.getGradeRequiredSign(), src.getGradeRequiredExec(), src.getTarget()){
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("Robotomy Request", 72, 45, target) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &) {
	return (*this);
}

void											RobotomyRequestForm::doExecute(Bureaucrat const & executor) const {
	std::cout << *this << " about to be executed by " << executor << std::endl;
	std::cout << "********** BZZZZ FRRR DRRR CHRRR KROUIKKKK *****************" << std::endl;
	srand(time(NULL));
	if (rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << this->getTarget() << " failed to be robotomized and died a painful death." << std::endl;
	}
}
