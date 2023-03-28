#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Default"), _hit_point(10), _energy_points(10), _attack_dmg(0)
{
	std::cout << "Constructor of ClapTrap : " << _name << " called and initialized values" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_points(10), _attack_dmg(0)
{
	std::cout << "Constructor of ClapTrap : " << _name << " called and initialized values" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_point(other._hit_point), _energy_points(other._energy_points), _attack_dmg(other._attack_dmg)
{
	std::cout << "Copy constructor called on ClapTrap" << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap : " << _name << " called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << this->_name << " attacked " << target << " and caused 50 damages" << std::endl;
	}
	else
		std::cout << "No more energy point to attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hit_point && this->_hit_point != 0)
	{
		this->_hit_point -= this->_hit_point;
		std::cout << this->_name << "is died after getting an attacked of " << amount << " damage !" << std::endl;
	}
	else if (amount < this->_hit_point)
	{
		this->_hit_point -= amount;
		std::cout << this->_name << "have been attacked and loose " << amount << " hit points !" << std::endl;

	}
	else
		std::cout << this->_name << " is already dead and can't do nothing" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount > 0)
	{
		this->_energy_points -= 1;
		this->_hit_point += amount;
		std::cout << this->_name << "healed with " << amount << " of hp !" << std::endl;
	}
	else
	{
		std::cout << "Cannot be repaired with this value ..." << std::endl;
	}
}
