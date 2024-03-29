#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	std::cout << "ScavTrap constructor : " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;
	std::cout << "ScavTrap constructor : " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called on " << other._name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap : " << _name << " called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap : " << this->_name << " entered in Gate keeper mode !" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0)
	{
		this->_energy_points -= 1;
		std::cout << "ScavTrap : "<< this->_name << " attacked " << target << " and caused 50 damages" << std::endl;
	}
	else
		std::cout << "ScavTrap have no more energy point to attack !" << std::endl;
}

