#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string.h>

int main(int ac, char **av)
{
	int i = 0;
	if (ac != 4)
	{
		std::cout << "Not the good syntax" << std::endl;
		return (1);
	}
	std::string str(av[1]);
	std::ifstream infile(str.c_str());
	size_t index = 0;
	int pos = 0;
	std::string tmp;
	std::string line;

	str += ".replace";
	std::ofstream outfile(str.c_str());

	if (!infile.is_open())
	{
		std::cout << "Can't open " << av[1] << std::endl;
		return (1);
	}
	if (!outfile.is_open())
	{
		infile.close();
		std::cout << "Can't open" << str << std::endl;
		return (1);
	}
	else
	{
		while (true)
		{
			pos = 0;
			if (i != 0)
				outfile << line << std::endl;
			std::getline(infile, line);
			while (!infile.eof())
			{
				tmp = &line[pos];
				index = tmp.find(av[2]);
				if (index == std::string::npos)
					break;
				line.erase(pos, line.length());
				tmp.erase(index, strlen(av[2]));
				tmp.insert(index, av[3]);
				pos = index + line.length() + strlen(av[3]);
				line += tmp;

			}
			i++;
		}
	}
	infile.close();
	outfile.close();
}
