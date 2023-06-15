
#include "BitcoinExchange.hpp"


// int check_input_synthax()
// {

// }



Bitcoin::Bitcoin()
{
	std::ifstream infile("data.csv");
	std::string tmp;
	std::string date;
	size_t index;
	std::getline(infile, tmp);
	while (!infile.eof())
	{
		index = tmp.find(",");
		if (index == std::string::npos)
			break; // throw error
		this->_bitcoin[tmp.substr(0, index)] = atof(tmp.substr(index + 1, std::string::npos).c_str());
		std::getline(infile, tmp);
	}

	std::cout << "Bitcoin class successfully created with a map of " << _bitcoin.size() << " values " << std::endl;
}





Bitcoin::~Bitcoin()
{

}

void	Bitcoin::getBitcoinValue(std::string date)
{
	std::map<std::string, double>::const_iterator it = _bitcoin.find(date);
	if (it != _bitcoin.end())
		std::cout << "Bitcoin price for the " << date << " founded : " << _bitcoin[date] << std::endl;
	else
    {
        // Trouver la date la plus proche en arrière

    }
        // Afficher la date la plus proche en arrière et son prix

}
