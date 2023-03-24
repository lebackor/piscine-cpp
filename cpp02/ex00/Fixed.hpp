#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed{
	public:
	Fixed();
	Fixed(const Fixed& instance);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed& ope);

	private:
	int	_Fixedpoint;
	static int const fract = 8;

};

#endif
