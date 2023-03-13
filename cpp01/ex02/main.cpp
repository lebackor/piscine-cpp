#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of STR = " << &str << std::endl;
	std::cout << "Address in stringPTR =  " << stringPTR << std::endl;
	std::cout << "Address in stringREF = " << &stringREF << std::endl;

	std::cout << "Value in str = "<< str << std::endl;
	std::cout << "Value in stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value in stringREF = " << stringREF << std::endl;
}
