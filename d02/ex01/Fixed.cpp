#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>
#include <string>

const int Fixed::nfb = 8;

Fixed::Fixed(void) : fpv(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int par) : fpv(par << Fixed::nfb){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float par){
	std::cout << "Float constructor called" << std::endl;
	this->fpv = roundf(par * (float)Fixed::pow(2, Fixed::nfb));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::pow(int const nbr, int const puissance) {
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
	return this->fpv;
}

void	Fixed::setRawBits(int const raw) {
	this->fpv = raw;
}

float	Fixed::toFloat(void) const {
	return (this->fpv / (float)Fixed::pow(2, Fixed::nfb));
}

int		Fixed::toInt(void) const {
	return (this->fpv >> Fixed::nfb);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat();
	return (o);
}
