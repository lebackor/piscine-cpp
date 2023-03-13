#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->_weaponB)
		std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
	else
		std::cout << this->_name << " cannot attack because he doesn't have any weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
	this->_weaponB = &club;
}
