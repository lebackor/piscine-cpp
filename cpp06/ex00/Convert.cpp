#include "Convert.hpp"

Convert::Convert(std::string str) : _value(str)
{
	std::cout << BOLDGREEN << "Convert class successfully created" << RESET << std::endl;
}

Convert::~Convert(){}

bool Convert::content_letters(const std::string& s) {
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (::isalpha(s[i])) {
			return true;
		}
	}
	return false;
}

bool Convert::content_point(const std::string& s) {
	int count = 0;
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '.') {
			count++;
		}
	}
	return count == 1;
}

bool Convert::content_number(const std::string& s) {
	for (std::size_t i = 0; i < s.size(); ++i) {
		if (::isdigit(s[i])) {
			return true;
		}
	}
	return false;
}
bool Convert::good_float_synthax(const std::string &s)
{
	size_t i = 0;
	while (isdigit(s.c_str()[++i]) != 0){}
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
	try
	{
		if ((content_letters(this->_value) == true && content_number(this->_value) == true && content_point(this->_value) == 1 && check_if_float(this->_value) == true) 
			|| this->_value.compare("-inff") == 0 || this->_value.compare("+inff") == 0 || this->_value.compare("nanf") == 0)
		{
			std::cout << MAGENTA << "Float recognized" << RESET << std::endl;
			this->_floatvalue = atof(this->_value.c_str());
			convert_all(this->_floatvalue);
		}
		else if ((content_letters(this->_value) == false && content_number(this->_value) == true && content_point(this->_value) == 1)
		|| this->_value.compare("-inf") == 0 || this->_value.compare("+inf") == 0 || this->_value.compare("nan") == 0)
		{
			std::cout << MAGENTA << "Double recognized" << RESET << std::endl;
			this->_doublevalue = atof(this->_value.c_str());
			convert_all(this->_doublevalue);

		}
		else if (content_letters(this->_value) == false && content_point(this->_value) != 1 && content_number(this->_value) == true)
		{
			std::cout << MAGENTA << "Int recognized" << RESET << std::endl;
			this->_intvalue = atoi(this->_value.c_str());
			convert_all(this->_intvalue);
		}
		else if (content_letters(this->_value) == true || content_number(this->_value) == true)
		{
			if (strlen(this->_value.c_str()) > 1)
				throw Convert::NotAChar();
			std::cout << MAGENTA << "Char recognized" << RESET << std::endl;
			this->_charvalue = this->_value.c_str()[0];
			convert_all(this->_charvalue);
		}	
		else
			throw Convert::IDKType();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

}

void Convert::convert_all(char a)
{
	std::cout << "Char : " << a << std::endl;
	std::cout << "Int : " << static_cast<int>(a) << std::endl;
	std::cout << "Float : " << static_cast<float>(a) << std::endl;
	std::cout << "Double : " << static_cast<double>(a) << std::endl;
}

void Convert::convert_all(int a)
{
	std::cout << "Int : " << a << std::endl;
	std::cout << "Float : " << static_cast<float>(a) << std::endl;
	std::cout << "Double : " << static_cast<double>(a) << std::endl;
	std::cout << "Char : " << static_cast<char>(a) << std::endl;
}

void Convert::convert_all(float a)
{
	std::cout << "Float : " << a << std::endl;
	std::cout << "Int : " << static_cast<int>(a) << std::endl;
	std::cout << "Double : " << static_cast<double>(a) << std::endl;
	std::cout << "Char : " << static_cast<char>(a) << std::endl;
}

void Convert::convert_all(double a)
{
	std::cout << "Double : " << a << std::endl;
	std::cout << "Float : " << static_cast<float>(a) << std::endl;
	std::cout << "Int : " << static_cast<int>(a) << std::endl;
	std::cout << "Char : " << static_cast<char>(a) << std::endl;
}