#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed{
	public:
	Fixed();
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(const Fixed& instance);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed& operator=(const Fixed& ope);

	private:
	int	_Fixedpoint;
	static int const fract = 8;

};

std::ostream& operator<<(std::ostream &o, const Fixed& fixed);

#endif
