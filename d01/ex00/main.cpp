#include "Pony.hpp"
#include <iostream>
#include <iomanip>

void ponyOnTheHeap() {
	Pony *rainbow_dash = new Pony("Rainbow Dash");

	rainbow_dash->walk(20);
	rainbow_dash->talk("Hey, Fluttershy, where are you ?! Oh gosh, she is 18 meters behind... Ugh.");
	delete rainbow_dash;
}

void ponyOnTheStack() {
	Pony fluttershy("Fluttershy");

	fluttershy.walk(2);
	fluttershy.talk("Wow, i'm tired... !");
}

int main() {

	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
	ponyOnTheStack();
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
	ponyOnTheHeap();
	std::cout << std::setw(80) << std::setfill('-') << "-" << std::endl;
	std::cout << "Exiting main..." << std::endl;

	return (0);
}
