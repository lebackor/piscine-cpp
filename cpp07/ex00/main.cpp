#include "whatever.hpp"

int main()
{
	int a = 5;
	int b = 10;
	std::string c = "chien";
	std::string d = "hipopotame";
	::swap(a, b);
	::swap(c, d);
	std::cout << "a  :" << a << ", b :" << b << std::endl;
	std::cout << "min = " << ::min(a, b) << std::endl;
	std::cout << "max = " << ::max(a, b) << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}