#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"


int main() {
	CentralBureaucracy a;
	std::string s[] = {"Jean Mi", "Rainbow Dash", "Apple Jack", "Fluttershy", "Twilight Sparkle", "Rarity", "Pinkie pie", "Derpy hooves", "JEAN MARIE LE PEN LE BUREAUCRATE DE LA MORT", "Marcel", "Come"};

	srand(time(NULL));
	for (int i = 0; i < 40; i++) {
		std::cout << "Adding a Bureaucrat." << std::endl;
		a.feed(new Bureaucrat(s[rand() % 11], (rand() % 149) + 1));
	}
	for (int i = 0; i < 60; i++) {
		std::cout << "Queuing a task." << std::endl;
		a.queueUp(s[rand() % 11]);
	}

	a.doBureaucracy();
}
