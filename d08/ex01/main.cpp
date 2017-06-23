#include "span.hpp"
#include <cstdlib>

int main() {
	Span a(5);

	a.addNumber(5);
	a.addNumber(3);
	a.addNumber(17);
	a.addNumber(9);
	a.addNumber(11);

	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;

	std::cout << std::endl;

	Span b(10);

	b.addNumber(2);
	b.addNumber(3);
	b.addNumber(5);
	b.addNumber(2);
	b.addNumber(0);


	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;

	std::cout << std::endl;

	srand(time(NULL));
	Span c(100000);
	for (int i = 0; i < 100000; i++) {
		c.addNumber(rand());
	}
	std::cout << "" <<  c.shortestSpan() << std::endl;
	std::cout << "" <<  c.longestSpan() << std::endl;

	std::cout << std::endl;

	try {
		Span d(2);
		d.addNumber(1);
		d.addNumber(1);
		d.addNumber(1);
	} catch (std::exception & e) {
		std::cout << "An exception occured: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Span d(2);
		d.addNumber(1);
		d.longestSpan();
	} catch (std::exception & e) {
		std::cout << "An exception occured: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	Span d(5);
	std::vector<int> v(5, 1);

	d.addElements(v.begin(), v.end());

	std::cout << "" <<  d.shortestSpan() << std::endl;
	std::cout << "" <<  d.longestSpan() << std::endl;


	std::cout << std::endl;

	try {
		Span f(2);
		std::vector<int> g(5, 1);

		f.addElements(g.begin(), g.end());
	} catch (std::exception & e) {
		std::cout << "An exception occured: " << e.what() << std::endl;
	}

	return (0);
}
