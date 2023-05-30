#include "BitcoinExchange.hpp"


int main()
{
	Bitcoin bitcoin;
	std::string name;

    std::ifstream input_file("input.txt");
    std::string line;
    std::regex line_regex("^(\\d{4}-\\d{2}-\\d{2})\\s*\\|\\s*(\\d+(\\.\\d+)?)$");

    // Vérifie chaque ligne du fichier d'entrée
    while (std::getline(input_file, line)) {
        std::smatch match;
        if (std::regex_match(line, match, line_regex)) {
            std::string date_str = match[1];
            std::string value_str = match[2];
            // Convertit la date et la valeur en types appropriés
            // et effectue le calcul nécessaire
            // ...
			bitcoin.getBitcoinValue(match[1]);
        } else {
            std::cerr << "Erreur : ligne invalide : " << line << std::endl;
        }
    }


}
