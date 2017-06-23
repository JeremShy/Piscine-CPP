#include "Human.hpp"
#include <iostream>

fhuman Human::tab[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

Human::Human() {

}

Human::~Human() {

}

void	Human::meleeAttack(std::string const & target) {
	std::cout << "Calling meleeAttack with target " << target << std::endl;
}
void	Human::rangedAttack(std::string const & target) {
	std::cout << "Calling rangedAttack with target " << target << std::endl;
}
void	Human::intimidatingShout(std::string const & target) {
	std::cout << "Calling intimidatingShout with target " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	std::string name[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	int index;
	for (int i = 0; i < 3; i++) {
		if (name[i] == action_name)
		{
			(this->*Human::tab[i])(target);
			return ;
		}
	}
	std::cout << "Human::action was called with an incorrect action_name parameter. (\"" << action_name << "\")" << std::endl;
}
