#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* zaz = new Character("zaz");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	tmp = src->createMateria("cure");
	zaz->equip(tmp);
	tmp = src->createMateria("ice");
	zaz->equip(tmp);
	zaz->unequip(1);
	ICharacter* bob = new Character("bob");
	zaz->use(0, *bob);
	zaz->use(1, *bob);
	delete bob;
	delete zaz;
	delete src;
	return 0;
}
