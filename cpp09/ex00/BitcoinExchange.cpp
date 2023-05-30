
#include "BitcoinExchange.hpp"


// int check_input_synthax()
// {

// }



// Bitcoin::Bitcoin()
// {
// 	std::ifstream infile("data.csv");
// 	std::string tmp;
// 	std::string date;
// 	size_t index;
// 	std::getline(infile, tmp);
// 	while (!infile.eof())
// 	{
// 		index = tmp.find(",");
// 		if (index == std::string::npos)
// 			break; // throw error
// 		this->_bitcoin[tmp.substr(0, index)] = atof(tmp.substr(index + 1, std::string::npos).c_str());
// 		std::getline(infile, tmp);
// 	}

// 	std::cout << "Bitcoin class successfully created with a map of " << _bitcoin.size() << "values " << std::endl;
// }
Bitcoin::Bitcoin()
{
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier" << std::endl;
        throw ;
    }

    // Stocker les dates et les prix dans une map de vecteurs
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date_str;
        double price;
        if (!(iss >> date_str >> price)) {
            std::cerr << "Erreur: Impossible de lire la ligne" << std::endl;
            continue;
        }
        this->_bitcoin[date_str] = price;
    }

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
        double price;
        std::string closest_date;
        double min_diff = std::numeric_limits<double>::max();
    for (std::map<std::string, double>::iterator it = this->_bitcoin.begin(); it != this->_bitcoin.end(); ++it) {
        std::tm tm1 = {0, 0, 0, -1, std::stoi(it->first.substr(8, 2)), std::stoi(it->first.substr(5, 2)) - 1, std::stoi(it->first.substr(0, 4)) - 1900, -1, 0};
        std::tm tm2 = {0, 0, 0, -1, std::stoi(date.substr(8, 2)), std::stoi(date.substr(5, 2)) - 1, std::stoi(date.substr(0, 4)) - 1900, -1, 0};
        std::time_t time1 = std::mktime(&tm1);
        std::time_t time2 = std::mktime(&tm2);
            double diff = std::difftime(time1, time2);
            if (diff >= 0 && diff < min_diff) {
                min_diff = diff;
                price = it->second;
                closest_date = it->first;
            }
    }
        // Afficher la date la plus proche en arrière et son prix
        std::cout << "Date la plus proche en arrière: " << closest_date << ", Prix: " << price << std::endl;
    }
}
