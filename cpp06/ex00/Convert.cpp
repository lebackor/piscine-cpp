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

bool isPrintable(char c) {
    return std::isprint(static_cast<unsigned char>(c)) != 0;
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

int comma_float_count(std::string str){
    int count = 0;
    int j = 0;
    while (str[j] && str[j] != '.')
        j++;
    if (!str[j])
        return (1);
    int k = j + 1;
    while (str[k] && str[k] == '0')
        k++;
    if (!str[k] || str[k] == 'f')
        return (1);
    for (int i = j + 1;str[i];i++){
        if (isdigit(str[i]))
            count++;
    }
    if (count > std::numeric_limits<float>::digits10 + 1)
        return (std::numeric_limits<float>::digits10 + 1);
    return (count);
}

int comma_double_count(std::string str){
    int count = 0;
    int j = 0;
    while (str[j] && str[j] != '.')
        j++;
    if (!str[j])
        return (1);
    int k = j + 1;
    while (str[k] && str[k] == '0')
        k++;
    if (!str[k] || str[k] == 'f')
        return (1);
    for (int i = j + 1;str[i];i++){
        if (isdigit(str[i]))
            count++;
    }
    if (count > std::numeric_limits<double>::digits10 + 1)
        return (std::numeric_limits<double>::digits10 + 1);
    return (count);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		if (result * sign > 2147483647)
			return (-1);
		else if (result * sign < -2147483648)
			return (0);
		i++;
	}
	return (result * sign);
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
	int count = 0;
	while (isdigit(s.c_str()[++i]) != 0){}
	if ((isdigit(s.c_str()[i]) == 0 && isalpha(s.c_str()[i]) == 0 && i != std::string::npos) || i == 1)
		return false;
	while (isalpha(s.c_str()[i]) != 0)
	{
		if (s.c_str()[i] == 'f')
			count++;
		else
			return false;
		i++;
	}
	if ((isalpha(s[i]) == 0 && isdigit(s[i]) != 0 && i != std::string::npos) ||  (count > 1 && i != std::string::npos))
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
		{
			std::cout << MAGENTA << "Float recognized" << RESET << std::endl;
		}
		else if ((content_letters(this->_value) == false && content_number(this->_value) == true && content_point(this->_value) == 1)
		|| this->_value.compare("-inf") == 0 || this->_value.compare("+inf") == 0 || this->_value.compare("nan") == 0)
		{
			std::cout << MAGENTA << "Double recognized" << RESET << std::endl;

		}
		else if (content_letters(this->_value) == false && content_point(this->_value) != 1 && content_number(this->_value) == true)
		{
			std::cout << MAGENTA << "Int recognized" << RESET << std::endl;

		}
		else if ((content_letters(this->_value) == true || content_number(this->_value) == true) && this->_value.size() == 1)
		{
			std::cout << MAGENTA << "Char recognized" << RESET << std::endl;
		}
		else
			throw Convert::IDKType();
}

bool isInvalidCharacter(const std::string& str, unsigned long i) {
    char currentChar = str[i];

    if (!isdigit(currentChar) && currentChar != '.' && currentChar != 'f') {
        if (i != 0 || currentChar != '-') {
            return true;
        }
    }

    return false;
}


int Convert::isstrValid(std::string str, std::string type){
	if (str.length() == 0){
		std::cout << "impossible" << std::endl;
    	return (0);}
for (unsigned long i = 0; str[i]; i++) {
    if (str[i] == '.' && !content_point(str)) {
        std::cout << "impossible" << std::endl;
        return 0;
    } else if (str.length() > 1 && str[0] == '-' && !isdigit(str[1])) {
        std::cout << "impossible" << std::endl;
        return 0;
    } else if (str.length() > 1 && isInvalidCharacter(str, i)) {
        std::cout << "impossible" << std::endl;
        return 0;
    } else if (str[i] == '.' && (i == str.length() - 1 || (i == str.length() - 2 && str[i + 1] == 'f'))) {
        std::cout << "impossible" << std::endl;
        return 0;
    } else if (str.length() > 1 && !content_point(str) && str[i] == 'f') {
        std::cout << "impossible" << std::endl;
        return 0;
    }
}
    if (type == "char" && str.length() == 1 && isalpha(str[0]))
        return (1);
    if (type == "char" && !isPrintable(ft_atoi(str.c_str()))){
        std::cout << "Non displayable" << std::endl;
        return (0);
	}
	return 1;
}

void    Convert::toChar(){
	std::cout << "Char : ";
	if (isstrValid(this->_value, "char"))
	{
	if (this->_value.length() == 1 && isalpha(this->_value[0]))
		std::cout << this->_value << std::endl;
	else
		std::cout << static_cast<char>(ft_atoi(this->_value.c_str())) << std::endl;
	}
}

void    Convert::toInt(){
	std::cout << "Int : ";
	if (isstrValid(this->_value, "int"))
	{
		if (this->_value.length() == 1 && isalpha(this->_value[0]))
			std::cout << static_cast<int>(this->_value[0]) << std::endl;
		else
			std::cout << ft_atoi(this->_value.c_str()) << std::endl;
	}
}

void    Convert::toFloat(){
	std::cout << "Float : ";
	if (this->_value == "nanf" || this->_value == "-inff" || this->_value == "+inff"){
		std::cout << this->_value << std::endl;
	}
	else if (this->_value == "nan" || this->_value == "-inf" || this->_value == "+inf"){
		std::cout << this->_value << "f" << std::endl;
	}
	else if (isstrValid(this->_value, "float"))
	{
		if (this->_value.length() == 1 && isalpha(this->_value[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(this->_value[0]) << "f" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(comma_float_count(this->_value)) << atof(this->_value.c_str()) << "f" << std::endl;
	}
}

void    Convert::toDouble(){
	std::cout << "Double : ";
	if (this->_value == "nanf" || this->_value == "nan"){
		std::cout << "nan" << std::endl;
	}
	else if (this->_value == "-inff" || this->_value == "-inf"){
		std::cout << "-inf" << std::endl;
	}
	else if (this->_value == "+inff" || this->_value == "+inf"){
		std::cout << "+inf" << std::endl;
	}
	else if (isstrValid(this->_value, "double"))
	{
		if (this->_value.length() == 1 && isalpha(this->_value[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(this->_value[0]) << std::endl;
		else
			std::cout << std::fixed << std::setprecision(comma_double_count(this->_value)) << atof(this->_value.c_str()) << std::endl;
	}
}
