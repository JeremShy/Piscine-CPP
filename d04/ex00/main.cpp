#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Idiot.hpp"

int main()
{
Sorcerer robert("Robert", "the Magnificent");
Victim jim("Jimmy");
Peon joe("Joe");
Idiot fred("Fred");
std::cout << robert << jim << joe << fred;
robert.polymorph(jim);
robert.polymorph(joe);
robert.polymorph(fred);

Victim *fluttershy = new Peon("fluttershy");
std::cout << *fluttershy;
robert.polymorph(*fluttershy);
delete fluttershy;

return 0;
}
