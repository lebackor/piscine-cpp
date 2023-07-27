
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <ctime>
#include <cmath>
#include <sstream>
#include <limits>
#include <ctime>
#include <regex.h>

class BitcoinExchange{
	public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &rhs);
	~BitcoinExchange();
    BitcoinExchange & operator=(const BitcoinExchange &other);
    void    read_csv();
	int parse(int y, int m, int d, std::string str_taux, float rate, std::string line);
	//  int     parse(int year, int month, int day, std::string raate, float rate, std::string     line);

	void print(std::string input, float btc);
	void read_input(std::string file);
	private:

	std::map<std::string, float> _bitcoin;


};

template <typename T>
std::string ToString(T value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}