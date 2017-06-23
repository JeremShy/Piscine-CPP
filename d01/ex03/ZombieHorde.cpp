#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(int N) : _horde(new Zombie[N]), _N(N){
	std::cout << "Created a zombie horde with " << N << " zombies." << std::endl;
}

ZombieHorde::~ZombieHorde() {
	delete [] this->_horde;
}

void ZombieHorde::announce() {
	for (int i = 0 ; i < this->_N ; i++) {
		std::cout << "[" << i << "] ";
		this->_horde[i].announce();
	}
}
