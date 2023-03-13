#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Zombie{
	private:
	std::string name;

	public:
	Zombie()
	{
		
	}
	~Zombie()
	{
		std::cout << this->name << " is deleted" << std::endl;
	}
	void announce(void);
	void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
