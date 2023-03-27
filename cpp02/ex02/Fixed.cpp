#include "Fixed.hpp"


Fixed::Fixed(void) : _Fixedpoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_Fixedpoint = nb << fract;
}

Fixed::Fixed(float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_Fixedpoint = int(roundf(nb * (1 << fract)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& instance) : _Fixedpoint(instance._Fixedpoint)
{
	std::cout << "Copy constructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_Fixedpoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_Fixedpoint = raw;
}

Fixed& Fixed::operator=(const Fixed& ope)
{
	std::cout << "Assignement operator called" << std::endl;
	this->_Fixedpoint = ope._Fixedpoint;
	return *this;
}

float Fixed::toFloat(void) const{

	return float(this->_Fixedpoint) / (1 << fract);
}

int Fixed::toInt(void) const
{
	return (this->_Fixedpoint >> fract);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed)
{
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator==(const Fixed& instance)
{
	return (this->_Fixedpoint == instance._Fixedpoint);
}

bool Fixed::operator!=(const Fixed& instance)
{
	return (this->_Fixedpoint != instance._Fixedpoint);
}

bool Fixed::operator<(const Fixed& instance)
{
	return (this->_Fixedpoint < instance._Fixedpoint);
}

bool Fixed::operator>(const Fixed& instance)
{
	return (this->_Fixedpoint > instance._Fixedpoint);
}

bool Fixed::operator>=(const Fixed& instance)
{
	return (this->_Fixedpoint >= instance._Fixedpoint);
}

bool Fixed::operator<=(const Fixed& instance)
{
	return (this->_Fixedpoint <= instance._Fixedpoint);
}

Fixed Fixed::operator+(const Fixed& instance)
{
	Fixed tmp;

	tmp.setRawBits(this->_Fixedpoint + instance._Fixedpoint);
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& instance)
{
	Fixed tmp;

	tmp.setRawBits(this->_Fixedpoint - instance._Fixedpoint);
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& instance)
{
	Fixed tmp;

	tmp.setRawBits(this->_Fixedpoint * instance._Fixedpoint >> fract);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& instance)
{
	Fixed tmp;

	tmp.setRawBits(this->_Fixedpoint * (1 << fract) / instance._Fixedpoint);
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->_Fixedpoint++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_Fixedpoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed& max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._Fixedpoint > b._Fixedpoint)
		return (a);
	return (b);

}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._Fixedpoint < b._Fixedpoint)
		return (a);
	return (b);
}

