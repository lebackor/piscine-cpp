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

void Convert::catch_and_convert()
{
	if (content_letters(this->_value) == true && content_number(this->_value) == true && content_point(this->_value) == 1)
		std::cout << MAGENTA << "Float recognized" << RESET << std::endl;
	else if (content_letters(this->_value) == false && content_number(this->_value) == true && content_point(this->_value) == 1)
		std::cout << MAGENTA << "Double recognized" << RESET << std::endl;
	else if (content_letters(this->_value) == false && content_point(this->_value) != 1 && content_number(this->_value) == true)
		std::cout << MAGENTA << "Int recognized" << RESET << std::endl;
	else if (content_letters(this->_value) == true || content_number(this->_value) == true)
		std::cout << MAGENTA << "String recognized" << RESET << std::endl;
	else
		std::cout << RED << "Cannot recognized a type" << RESET << std::endl;
}
