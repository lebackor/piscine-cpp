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
	Zombie(std::string name) : name(name){
		std::cout << name << " is created" << std::endl;
	}
	~Zombie()
	{
		std::cout << this->name << " is deleted" << std::endl;
	}
	void announce(void);
};

	Zombie* newZombie( std::string name );
	void randomChump( std::string name );


#endif
