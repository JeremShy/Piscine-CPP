#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(const int par);
	Fixed(const float par);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);
	static int 	pow(int const nbr, int const puissance);
	bool operator  >(Fixed const & rhs) const;
	bool operator  <(Fixed const & rhs) const;
	bool operator >=(Fixed const & rhs) const;
	bool operator <=(Fixed const & rhs) const;
	bool operator ==(Fixed const & rhs) const;
	bool operator !=(Fixed const & rhs) const;

	Fixed operator +(const Fixed & rhs);
	Fixed operator -(const Fixed & rhs);
	Fixed operator *(const Fixed & rhs);
	Fixed operator /(const Fixed & rhs);

	Fixed operator++(int val); // post inc
	Fixed & operator++(); // pre inc
	Fixed operator--(int val); // post dec
	Fixed & operator--(); // pre dec

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;

	int		toInt(void) const;

	static Fixed const & min(Fixed const & s1, Fixed const &s2);
	static Fixed & min(Fixed & s1, Fixed &s2);

	static Fixed const & max(Fixed const & s1, Fixed const &s2);
	static Fixed & max(Fixed & s1, Fixed &s2);

private:
	int fpv; // Fixed point value;
	static int const nfb; // Number of fractional bits
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
