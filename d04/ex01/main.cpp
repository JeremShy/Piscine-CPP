#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;

	zaz->equip(pf);

	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	std::cout << "--------------------" << std::endl;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	std::cout << "--------------------" << std::endl;

	Enemy *k = new SuperMutant();
	zaz->equip(pr);
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	zaz->attack(k);
	std::cout << *zaz;
	std::cout << "--------------------" << std::endl;

	std::cout << "--------------------" << std::endl;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	std::cout << "--------------------" << std::endl;

	delete k;
	k = new SuperMutant();
	Enemy *l = new SuperMutant();
	zaz->attack(k);
	std::cout << *zaz;
	std::cout << k->getType() << "'s hp : " << k->getHP() << std::endl;
	*k = *l; // Test de la surcharge de l'opérateur =
	std::cout << k->getType() << "'s hp : " << k->getHP() << std::endl;
	delete l;
	l = new RadScorpion();
	*k = *l; // Test de la surcharge de l'opérateur = avec polymorphisme
	std::cout << k->getType() << "'s hp : " << k->getHP() << std::endl;


	delete k;
	delete l;
	delete zaz;
	delete pf;
	return 0;
}
