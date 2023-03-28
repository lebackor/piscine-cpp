#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;
	std::cout << "FragTrap constructor : " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;
	std::cout << "FragTrap constructor : " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called on " << other._name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap : " << _name << " called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : " << this->_name << " would like to high fives the boys !" << std::endl;
}
