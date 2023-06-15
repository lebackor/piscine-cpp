#include "BitcoinExchange.hpp"


int main()
{
	Bitcoin bitcoin;
	std::map<std::string, double> _input;
	std::string tmp;
	size_t index;
	std::ifstream input_file("input.txt");
	std::getline(input_file, tmp);
	while (!input_file.eof())
	{
		index = tmp.find('|');
		if (index == std::string::npos)
			break; // throw error
		_input[tmp.substr(0, index)] = atof(tmp.substr(index + 1, std::string::npos).c_str());

	}
}
