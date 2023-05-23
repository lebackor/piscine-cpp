#include "iter.hpp"

void print_lower(const std::string& str)
{
	for (std::string::const_iterator itr = str.cbegin(); itr != str.cend(); itr++)
		std::cout << (char)tolower(*itr);
	std::cout << std::endl;
}

void print_upper(const std::string& str)
{
	for (std::string::const_iterator itr = str.cbegin(); itr != str.cend(); itr++)
		std::cout << (char)toupper(*itr);
	std::cout << std::endl;
}

int main()
{
	std::string strings[] = {"Un", "Deux", "Trois", "Quatre"};

	std::cout << "Normal: "<< std::endl;
	::iter(strings, 4, printElement<std::string>);
	std::cout << "Lower: "<< std::endl;
	::iter(strings, 4, print_lower);
	std::cout << "Upper: "<< std::endl;
	::iter(strings, 4, print_upper);
}
