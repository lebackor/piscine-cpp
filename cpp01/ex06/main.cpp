#include "Harl.hpp"


// int main()
// {
// 	Harl harl;

// 	harl.complain("ERROR");
// 	harl.complain("DEBUG");
// 	harl.complain("WARNING");
// 	harl.complain("INFO");
// 	harl.complain("INF");
// }

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return -1;
	}
	else
		harl.complain(av[1]);
}
