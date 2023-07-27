
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{

}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	this->operator=(rhs);
}


BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

void BitcoinExchange::read_csv()
{
	std::string data;
	std::ifstream tmp;
	
	tmp.open("./data.csv");
  	if (!tmp.is_open())
        throw std::runtime_error("Error opening file: data.csv");
	while (!tmp.eof())
	{
		tmp >> data;
		std::string date = data.substr(0, 10).erase(4, 1).erase(6, 1);
		float taux = 0.0;
		std::stringstream convert;
		convert << data.substr(11);
		convert >> taux;
		_bitcoin.insert(std::make_pair(date, taux));
	}
	tmp.close();
}



int BitcoinExchange::parse(int y, int m, int d, std::string str_taux, float rate, std::string line)
{
    int end_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int tmp = line.find("|");
    if (line[tmp + 1] != ' ' || line[tmp - 1] != ' ')
    {
        std::cerr << "Error: Invalid Pipe" << std::endl;
        return -1;
    }

    if (line[4] != '-' || line[7] != '-')
    {
        std::cerr << "Error: Invalid date format" << std::endl;
        return -1;
    }

    if (str_taux[0] == '.' || str_taux.find_first_not_of("0123456789.") != std::string::npos)
    {
        std::cerr << "Error: Invalid rate format" << std::endl;
        return -1;
    }

    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > end_months[m - 1])
    {
        std::cerr << "Error: Invalid date format or month out of range" << std::endl;
        return -1;
    }

    if (rate < 0.00 || rate > 1000.00)
    {
        std::cerr << "Error: Rate out of range" << std::endl;
        return -1;
    }

    return 0;
}

void    BitcoinExchange::print(std::string inputdate, float bitcoins)
{
    std::map<std::string, float>::iterator itb = _bitcoin.begin();
    std::map<std::string, float>::iterator ite = _bitcoin.end();
    bool    flag = false;

	while (itb != ite)
	{
		if (itb->first == inputdate)
		{
			flag = true;
			break;
		}
		itb++;
	}
    if (flag == true)
    {
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " <<  std::fixed << std::setprecision(2) << bitcoins * itb->second << std::endl;
        flag = false;
    }
    else
    {
        ite = _bitcoin.lower_bound(inputdate);
        std::cout << inputdate.insert(4,"-").insert(7,"-") << " => " << bitcoins << " = " << std::fixed << std::setprecision(2) << bitcoins * ite->second << std::endl;
    }
}

void BitcoinExchange::read_input(std::string file)
{
    std::ifstream input;
    std::string line;

    input.open(file.c_str());

    if (input.fail())
    {
        input.close();
        throw std::runtime_error("Error, could not open file.");
    }
	std::getline(input, line);
    while (std::getline(input, line))
    {
        std::string date;
        int year, month, day = 0;
        std::stringstream y, m, d;
        y << line.substr(0, 4);
        m << line.substr(5, 2);
        d << line.substr(8, 2);
        y >> year;
        m >> month;
        d >> day;
        if (line.length() < 14)
        {
            std::cerr << "Invalid Format" << std::endl;
            continue;
        }

        std::string str_taux = line.substr(13);
        float btc = 0.00;
        std::stringstream bitcoin;

        bitcoin << str_taux;
        bitcoin >> btc;

        if (month < 10 && day < 10)
            date = ToString(year * 10) + ToString(month * 10) + ToString(day);
        else if (day < 10)
            date = ToString(year) + ToString(month * 10) + ToString(day);
        else if (month < 10)
            date = ToString(year * 10) + ToString(month) + ToString(day);
        else
            date = ToString(year) + ToString(month) + ToString(day);

        if (parse(year, month, day, str_taux, btc, line) == 0)
            print(date, btc);
	}

    input.close();
}
