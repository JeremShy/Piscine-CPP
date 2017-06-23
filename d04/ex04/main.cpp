#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"

int main() {
	MiningBarge m1;

	IMiningLaser	*d = new DeepCoreMiner();
	IMiningLaser	*s = new StripMiner();
	BocalSteroid	b("Bocal Steroid");
	AsteroBocal		a("Astero Bocal");

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-------------For m1----------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;

	m1.equip(d);
	m1.equip(s);


	std::cout << "On Bocal Steroid :" << std::endl;
	m1.mine(&b);

	std::cout << std::endl << "On Astero Bocal :" << std::endl;
	m1.mine(&a);

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-------------For m2----------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;

	MiningBarge m2 = m1;
	std::cout << "On Bocal Steroid :" << std::endl;
	m2.mine(&b);

	std::cout << std::endl << "On Astero Bocal :" << std::endl;
	m2.mine(&a);

	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "-------------For m3----------------" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;

	MiningBarge m3;
	IMiningLaser	*d2 = new DeepCoreMiner();
	IMiningLaser	*s2 = new StripMiner();
	IMiningLaser	*d3 = new DeepCoreMiner();
	IMiningLaser	*d4 = new DeepCoreMiner();
	IMiningLaser	*s3 = new StripMiner();

	m3.equip(d2);
	m3.equip(s2);
	m3.equip(d3);
	m3.equip(d4);
	m3.equip(s3);

	std::cout << "On Bocal Steroid :" << std::endl;
	m3.mine(&b);

	std::cout << std::endl << "On Astero Bocal :" << std::endl;
	m3.mine(&a);


}
