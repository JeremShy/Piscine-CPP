#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat a("Michel", 149); // Tres tres nul.
	Bureaucrat b("Nicolas", 1); // Quelle puissance !
	Bureaucrat c("Fred", 40); // Plutot bon !

	std::cout << "-----------------------------------------------------" << std::endl;

	Form f("CERFA 666Bis", 40, 60);

	a.signForm(f);
	std::cout << "-----------------------------------------------------" << std::endl;
	b.signForm(f);
	std::cout << "-----------------------------------------------------" << std::endl;
	c.signForm(f);
	std::cout << "-----------------------------------------------------" << std::endl;

	try {
		Form g("Laisser passer A 38", 0, 0);
	} catch (std::exception & e){
		std::cout << "Exception caught : " << e.what() << std::endl;
		std::cout << "Asterix : LE LAISSER-PASSER A38 !!" << std::endl;
	}
}
