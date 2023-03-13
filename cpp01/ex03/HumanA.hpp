#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
	std::string _name;
	Weapon& _weaponA;

	public:
	HumanA(std::string name, Weapon &_weaponA): _name(name), _weaponA(_weaponA)
	{

	}
	~HumanA(){

	}
	void	attack();
};

#endif
