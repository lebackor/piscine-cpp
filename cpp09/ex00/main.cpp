#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{

	if (ac != 2)
		throw std::runtime_error("Error, indicate only one file");
	
	try
	{
		BitcoinExchange btc;
		btc.read_csv();
		btc.read_input(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
