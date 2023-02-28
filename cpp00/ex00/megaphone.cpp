#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av){

	std::string str = "";
	std::string test;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int j = 1; j < ac; j++){
		test = av[j];
		int len = test.length();
		for (int i = 0; i < len; i++){
			str = std::toupper(av[j][i]);
			std::cout << str;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
