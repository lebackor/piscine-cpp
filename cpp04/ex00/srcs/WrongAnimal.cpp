#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "Wrong animal void constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Wrong animal : " << type << " constructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->_type << " can't make a noice" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor wrong animal called" << std::endl;
}
