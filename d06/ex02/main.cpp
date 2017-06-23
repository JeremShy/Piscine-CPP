#include "Base.hpp"

int main ()
{
	Base *p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);

	std::cout << "--------------------------------------------" << std::endl;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);

	std::cout << "--------------------------------------------" << std::endl;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);

	std::cout << "--------------------------------------------" << std::endl;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);

	std::cout << "--------------------------------------------" << std::endl;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
}
