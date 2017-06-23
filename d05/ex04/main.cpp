#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"


int main() {
	Bureaucrat	a("Michel", 70);
	Bureaucrat	b("Nicolas", 100);
	Intern			i;
	OfficeBlock bl;

	bl.setIntern(&i);
	bl.setSigner(&a);
	bl.setExecutor(&b);

	std::cout << "-----------------------------------------------------" << std::endl;

	try {
		bl.doBureaucracy("presidential pardon", "Michel Berger");
	} catch (OfficeBlock::CreationException & e) {
		std::cout << "There was an error while creating the form" << std::endl;
	} catch (OfficeBlock::SigningException & e) {
		std::cout << "There was an error while signing the form" << std::endl;
	} catch (OfficeBlock::ExecutingException & e) {
		std::cout << "There was an error while executing the form" << std::endl;
	}

	std::cout << "-----------------------------------------------------" << std::endl;

	try {
		bl.doBureaucracy("robotomy request", "Francis Lalanne");
	} catch (OfficeBlock::CreationException & e) {
		std::cout << "There was an error while creating the form" << std::endl;
	} catch (OfficeBlock::SigningException & e) {
		std::cout << "There was an error while signing the form" << std::endl;
	} catch (OfficeBlock::ExecutingException & e) {
		std::cout << "There was an error while executing the form" << std::endl;
	}

	std::cout << "-----------------------------------------------------" << std::endl;

	try {
		bl.doBureaucracy("shrubbery creation", "Versailles");
	} catch (OfficeBlock::CreationException & e) {
		std::cout << "There was an error while creating the form" << std::endl;
	} catch (OfficeBlock::SigningException & e) {
		std::cout << "There was an error while signing the form" << std::endl;
	} catch (OfficeBlock::ExecutingException & e) {
		std::cout << "There was an error while executing the form" << std::endl;
	}

	std::cout << "-----------------------------------------------------" << std::endl;

	try {
		bl.doBureaucracy("ponies termination", "Versailles");
	} catch (OfficeBlock::CreationException & e) {
		std::cout << "There was an error while creating the form" << std::endl;
	} catch (OfficeBlock::SigningException & e) {
		std::cout << "There was an error while signing the form" << std::endl;
	} catch (OfficeBlock::ExecutingException & e) {
		std::cout << "There was an error while executing the form" << std::endl;
	}
}
