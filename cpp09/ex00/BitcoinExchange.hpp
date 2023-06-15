
#pragma once
#include <iostream>
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

class Bitcoin{
	public:

	Bitcoin();
	~Bitcoin();
	void getBitcoinValue(std::string date);
	private:

	std::map<std::string, double> _bitcoin;


};
