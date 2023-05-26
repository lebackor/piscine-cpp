#include "BitcoinExchange.hpp"


int main()
{
	Bitcoin bitcoin;
	std::string name;

	std::cout << "Envoie une date" << std::endl;
	std::cin >> name;
	bitcoin.getBitcoinValue(name);
}
