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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;

	int		toInt(void) const;
	static int 	pow(int const nbr, int const puissance);
private:
	int fpv; // Fixed point value;
	static int const nfb; // Number of fractional bits
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif
