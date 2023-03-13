#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	std::cout << this->name << " is created" << std::endl;
}
