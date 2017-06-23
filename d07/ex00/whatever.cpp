#include <iostream>
#include <string>

template<typename T>
void	swap(T & a, T & b) {
	T c;

	c = a;
	a = b;
	b = c;
}

template<typename T>
T		min(T const & a, T const & b) {
	if (a < b) {
		return (a);
	} else if (b < a) {
		return (b);
	} else {
		return (b);
	}
}

template<typename T>
T		max(T const & a, T const & b) {
	if (a > b) {
		return (a);
	} else if (b > a) {
		return (b);
	} else {
		return (b);
	}
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
