#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	private:
	std::string _name;
	Weapon* _weaponB;

	public:
	HumanB(std::string name): _name(name), _weaponB(NULL)
	{
		return;
	}
	~HumanB(){

	}
	void	attack();
	void	setWeapon(Weapon &club);
};

#endif
