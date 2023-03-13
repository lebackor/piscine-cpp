#include "Zombie.hpp"

int main()
{
	Zombie* zombie = NULL;

	zombie = newZombie("alien");
	randomChump("Alien 2");
	delete zombie;
}
