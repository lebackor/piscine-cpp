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

	void setRawBits(int const raw);
	int getRawBits(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	static Fixed& max(Fixed &a, Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);

	Fixed& operator=(const Fixed& ope);

	bool operator==(const Fixed& instance);
	bool operator!=(const Fixed& instance);
	bool operator<(const Fixed& instance);
	bool operator>(const Fixed& instance);
	bool operator>=(const Fixed& instance);
	bool operator<=(const Fixed& instance);

	Fixed operator+(const Fixed& instance);
	Fixed operator-(const Fixed& instance);
	Fixed operator*(const Fixed& instance);
	Fixed operator/(const Fixed& instance);

	Fixed operator++(int);
	Fixed& operator++();

	Fixed operator--(int);
	Fixed& operator--();

	private:
	int	_Fixedpoint;
	static int const fract = 8;

};

std::ostream& operator<<(std::ostream &o, const Fixed& fixed);

#endif
