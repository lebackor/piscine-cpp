#include "Convert.hpp"

int is_str_ascii(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!isascii(str[i]))
			return (1);
		i++;
	}
	return (0);
}



int main(int ac, char **av)
{
	if (ac > 2)
		return (std::cout << RED << "Too much arguments !" << RESET << std::endl, 0);
	if (ac == 1)
		return (std::cout << RED << "Not enough arguments !"<< RESET << std::endl, 0);
	std::string str(av[1]);
	if (is_str_ascii(str) == 0)
		std::cout << GREEN << "ASCII Recognized" << RESET  << std::endl;
	else
	{
		std::cout << RED << "NOT ASCII RECOGNIZED" << RESET << std::endl;
		return (1);
	}
	try
	{
		Convert convert(str);
		convert.catch_and_convert();
		convert.toFloat();
		convert.toDouble();
		convert.toInt();
		convert.toChar();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}
