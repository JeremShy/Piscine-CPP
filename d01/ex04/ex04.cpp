#include <iostream>
#include <string>

int main (void){
	std::string a("HI THIS IS BRAIN");

	std::string *ptr = &a;
	std::string &ref = a;

	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}
