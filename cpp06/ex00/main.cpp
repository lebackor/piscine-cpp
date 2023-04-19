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
	Convert convert(str);
	convert.catch_and_convert();
}

// 1f.0 doit string or il float
// f10.0 doit string or il float