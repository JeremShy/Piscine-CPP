#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main() {
	Bureaucrat a("Michel", 149); // Tres tres nul.
	Bureaucrat b("Nicolas", 1); // Quelle puissance !
	Bureaucrat c("Fred", 40); // Plutot bon !

	std::cout << "-----------------------------------------------------" << std::endl;

	PresidentialPardonForm f1("Yasuo");
	PresidentialPardonForm f2("Marc");

	a.signForm(f1);
	std::cout << "-----------------------------------------------------" << std::endl;
	b.signForm(f2);
	std::cout << "-----------------------------------------------------" << std::endl;

	a.executeForm(f1);
	std::cout << "-----------------------------------------------------" << std::endl;

	b.executeForm(f2);
	std::cout << "-----------------------------------------------------" << std::endl;

	b.executeForm(f1);
	std::cout << "-----------------------------------------------------" << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;
	ShrubberyCreationForm f3("Castle of Friendship");
	b.signForm(f3);
	b.executeForm(f3);
	std::cout << "-----------------------------------------------------" << std::endl;
}
