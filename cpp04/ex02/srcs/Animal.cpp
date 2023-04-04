#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor void called" << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << "An Animal " << name << " constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed :/" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Default animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}
