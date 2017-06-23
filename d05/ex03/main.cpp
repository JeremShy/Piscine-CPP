#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main() {
	Bureaucrat a("Michel", 149);	// Tres tres nul.
	Bureaucrat b("Nicolas", 1);		// Quelle puissance !
	Bureaucrat c("Fred", 40);			// Plutot bon !
	Intern jeremy;

	std::cout << "-----------------------------------------------------" << std::endl;

	Form *f1 = jeremy.makeForm("presidential pardon", "Yasuo");
	Form *f2 = jeremy.makeForm("robotomy request", "Marc");
	Form *f3 = jeremy.makeForm("shrubbery creation", "Jardinet");
	std::cout << "-----------------------------------------------------" << std::endl;

	a.signForm(*f1);
	std::cout << "-----------------------------------------------------" << std::endl;
	b.signForm(*f2);
	std::cout << "-----------------------------------------------------" << std::endl;

	a.executeForm(*f1);
	std::cout << "-----------------------------------------------------" << std::endl;

	b.executeForm(*f2);
	std::cout << "-----------------------------------------------------" << std::endl;

	b.executeForm(*f1);
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;

	b.signForm(*f3);
	b.executeForm(*f3);
	std::cout << "-----------------------------------------------------" << std::endl;

	delete f1;
	delete f2;
}
