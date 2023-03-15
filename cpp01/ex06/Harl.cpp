#include "Harl.hpp"

int	find_index(std::string level)
{
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(str[i]) == 0)
			return (i);
	}
	return (-1);
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	MemFuncPtr ArrayPtr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = find_index(level);
	int m = 0;
	if (i == -1)
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		switch(i)
		{
			case 0:
				m = 0;
				break;
			case 1:
				m = 1;
				break;
			case 2:
				m = 2;
				break;
			case 3:
				m = 3;
				break;
		}
	}
	for (int j = m; j < 4; j++)
		(this->*(ArrayPtr[j]))();
}

// demande si il ne trouve pas de level, erreur only ou error et print le reste

