#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Shrubbery Creation", 145, 137, "Default target"){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : Form(src.getName(), src.getGradeRequiredSign(), src.getGradeRequiredExec(), src.getTarget()){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery Creation", 145, 137, target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &) {
	return (*this);
}

void											ShrubberyCreationForm::doExecute(Bureaucrat const & executor) const {
	std::cout << *this << " about to be executed by " << executor << std::endl;

	std::ofstream f;

	f.exceptions(std::fstream::failbit);
	f.open(this->getTarget() + "_shrubbery", std::fstream::app);
	f <<
		"               ,@@@@@@@," << std::endl <<
		"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
		"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
		"       |o|        | |         | |" << std::endl <<
		"       |.|        | |         | |" << std::endl <<
		"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	f <<
		"               ,@@@@@@@," << std::endl <<
		"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
		"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
		"       |o|        | |         | |" << std::endl <<
		"       |.|        | |         | |" << std::endl <<
		"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	f <<
		"               ,@@@@@@@," << std::endl <<
		"       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
		"   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
		"       |o|        | |         | |" << std::endl <<
		"       |.|        | |         | |" << std::endl <<
		"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;


	f.close();

}
