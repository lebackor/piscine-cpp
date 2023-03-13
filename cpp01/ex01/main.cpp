#include "Zombie.hpp"

int main()
{
	Zombie	*zombie = NULL;

	zombie = zombieHorde(10, "ALIEN");
	delete [] zombie;
}
