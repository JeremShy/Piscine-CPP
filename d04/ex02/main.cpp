#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;


	std::cout << "vlc->getCount(): " << vlc->getCount() << std::endl;
	vlc->push(bob);
	vlc->push(jim);
	std::cout << "vlc->getCount(): " << vlc->getCount() << std::endl;
	vlc->push(bob);
	vlc->push(NULL);
	std::cout << "vlc->getCount(): " << vlc->getCount() << std::endl;
	ISpaceMarine* rd = new TacticalMarine;
	vlc->push(rd);
	std::cout << "vlc->getCount(): " << vlc->getCount() << std::endl;

	std::cout << "On the stack:" << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;

	std::cout << std::endl << std::endl;

	Squad vlc2;

	vlc2.push(new TacticalMarine());
	vlc2.push(new TacticalMarine());
	vlc2.push(new AssaultTerminator());

	std::cout << "On the heap:" << std::endl;
	for (int i = 0; i < vlc2.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	return 0;
}
