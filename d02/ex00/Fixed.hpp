#ifndef Fixed_CLASS_H
# define Fixed_CLASS_H

class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=(Fixed const & rhs);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int fpv; // Fixed point value;
	static int const nfb; // Number of fractional bits
	
	static int pow(int const nbr, int const puissance);
};

#endif
