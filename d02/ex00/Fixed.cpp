#include "Fixed.hpp"
#include <iostream>

const int Fixed::nfb = 8;

Fixed::Fixed(void) : fpv(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::pow(int const nbr, int const puissance) {
	int	i;

	i = 0;
	if (puissance == 0)
		return (1);
	if (nbr == 0)
		return (0);
	return (nbr * Fixed::pow(nbr, puissance - 1));
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->fpv = rhs.getRawBits();
	return (*this);
}

int 	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fpv;
}
void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fpv = raw;
}
