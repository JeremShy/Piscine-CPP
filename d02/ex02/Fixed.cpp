#include "Fixed.hpp"
#include <iostream>
#include <tgmath.h>
#include <string>

const int Fixed::nfb = 8;

Fixed::Fixed(void) : fpv(0){
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed::Fixed(const int par) : fpv(par << Fixed::nfb){
}

Fixed::Fixed(const float par){
	this->fpv = roundf(par * (float)Fixed::pow(2, Fixed::nfb));
}

Fixed::~Fixed(void) {
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
	this->fpv = roundf(rhs.getRawBits());
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

bool Fixed::operator>(Fixed const & rhs) const {
	return (this->fpv  > rhs.fpv);
}

bool Fixed::operator<(Fixed const & rhs) const {
	return (this->fpv  < rhs.fpv);
}

bool Fixed::operator>=(Fixed const & rhs) const {
	return (this->fpv >= rhs.fpv);
}

bool Fixed::operator<=(Fixed const & rhs) const {
	return (this->fpv <= rhs.fpv);
}

bool Fixed::operator==(Fixed const & rhs) const {
	return (this->fpv == rhs.fpv);
}

bool Fixed::operator!=(Fixed const & rhs) const {
	return (this->fpv != rhs.fpv);
}

Fixed Fixed::operator+(const Fixed & rhs) {
	float f = this->toFloat() + rhs.toFloat();
	Fixed ret(f);

	return (ret);
}

Fixed Fixed::operator-(const Fixed & rhs) {
	float f = this->toFloat() - rhs.toFloat();
	Fixed ret(f);

	return (ret);
}

Fixed Fixed::operator*(const Fixed & rhs) {
	float f = this->toFloat() * rhs.toFloat();
	Fixed ret(f);

	return (ret);
}

Fixed Fixed::operator/(const Fixed & rhs) {
	float f = this->toFloat() / rhs.toFloat();
	Fixed ret(f);

	return (ret);
}

Fixed Fixed::operator++(int val) {
	(void)val;
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed & Fixed::operator++() {
	this->fpv = (((this->fpv / (float)Fixed::pow(2, Fixed::nfb)) + (1 / (float)Fixed::pow(2, Fixed::nfb))) * (float)Fixed::pow(2, Fixed::nfb));
	return (*this);
}

Fixed Fixed::operator--(int val) {
	(void)val;
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed & Fixed::operator--() {
	this->fpv = ((this->fpv / (float)Fixed::pow(2, Fixed::nfb)) - 1 / (float)Fixed::pow(2, Fixed::nfb)) * (float)Fixed::pow(2, Fixed::nfb);
	return (*this);
}


Fixed const & Fixed::min(Fixed const & s1, Fixed const &s2) {
	if (s1.toFloat() >= s2.toFloat()) {
		return (s2);
	}
	return (s1);
}
Fixed & Fixed::min(Fixed & s1, Fixed &s2) {
	if (s1.toFloat() >= s2.toFloat()) {
		return (s2);
	}
	return (s1);
}

Fixed const & Fixed::max(Fixed const & s1, Fixed const &s2) {
	if (s1.toFloat() <= s2.toFloat()) {
		return (s2);
	}
	return (s1);
}
Fixed & Fixed::max(Fixed & s1, Fixed &s2) {
	if (s1.toFloat() <= s2.toFloat()) {
		return (s2);
	}
	return (s1);
}
