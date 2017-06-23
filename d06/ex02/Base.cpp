#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>

Base::~Base() {

}

Base	*generate(void) {

	static int i = 0;
	if (i == 0)
	{
		srand(time(NULL));
		i = 1;
	}
	int r = rand() % 3;

	if (r == 0) {
		std::cout << "Generating : A" << std::endl;
		return new A;
	}
	else if (r == 1) {
		std::cout << "Generating : B" << std::endl;
		return new B;
	}
	else {
		std::cout << "Generating : C" << std::endl;
		return new C;
	}
}

void	identify_from_pointer(Base *p)
{
	A *a = dynamic_cast<A*>(p);

	if (a) {
		std::cout << "A" << std::endl;;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b) {
		std::cout << "B" << std::endl;;
		return ;
	}

	std::cout << "C" << std::endl;;
	return ;
}

void	identify_from_reference(Base & p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch(std::bad_cast) {
	}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch(std::bad_cast) {
	}

	std::cout << "C" << std::endl;

}
