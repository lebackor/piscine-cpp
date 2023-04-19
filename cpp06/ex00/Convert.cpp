#include "Convert.hpp"

Convert::Convert(std::string str) : _value(str)
{
	std::cout << BOLDGREEN << "Convert class successfully created" << RESET << std::endl;
}

Convert::~Convert(){}

bool Convert::content_letters(const std::string& s) {
	return std::any_of(s.begin(), s.end(), ::isalpha);
}
bool Convert::content_point(const std::string& s) {
	return std::count(s.begin(), s.end(), '.') == 1;
}

bool Convert::content_number(const std::string& s) {
    return std::any_of(s.begin(), s.end(), ::isdigit);
}

bool Convert::good_float_synthax(const std::string &s)
{
	size_t i = 0;
	while (isdigit(s.c_str()[++i]) != 0)
	{
		std::cout  << "i = " << s.c_str()[i] << std::endl;
	}
	if ((isdigit(s.c_str()[i]) == 0 && isalpha(s.c_str()[i]) == 0 && i != std::string::npos) || i == 1)
		return false;	
	while (isalpha(s.c_str()[i]) != 0)
		i++;
	if (isalpha(s[i]) == 0 && isdigit(s[i]) != 0 && i != std::string::npos)
		return false;
	return true;
}


bool Convert::check_if_float(const std::string& s)
{
	std::string tmp;

	size_t i = s.find('.');
	if (i == std::string::npos)
		return (false);
	std::string first_part = s.substr(0, i);
	std::string end_part = s.substr(i, std::string::npos);
	if (content_letters(first_part) == false && good_float_synthax(end_part) == true)
		return true;
	else
		return false;
}

void Convert::catch_and_convert()
{
	if ((content_letters(this->_value) == true && content_number(this->_value) == true && content_point(this->_value) == 1 && check_if_float(this->_value) == true) 
		|| this->_value.compare("-inff") == 0 || this->_value.compare("+inff") == 0 || this->_value.compare("nanf") == 0)
		std::cout << MAGENTA << "Float recognized" << RESET << std::endl;
	else if ((content_letters(this->_value) == false && content_number(this->_value) == true && content_point(this->_value) == 1)
	|| this->_value.compare("-inf") == 0 || this->_value.compare("+inf") == 0 || this->_value.compare("nan") == 0)
		std::cout << MAGENTA << "Double recognized" << RESET << std::endl;
	else if (content_letters(this->_value) == false && content_point(this->_value) != 1 && content_number(this->_value) == true)
		std::cout << MAGENTA << "Int recognized" << RESET << std::endl;
	else if (content_letters(this->_value) == true || content_number(this->_value) == true)
		std::cout << MAGENTA << "String recognized" << RESET << std::endl;
	else
		std::cout << RED << "Cannot recognized a type" << RESET << std::endl;
}
