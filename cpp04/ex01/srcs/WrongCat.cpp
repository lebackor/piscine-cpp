#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
	std::cout << "WrongCat void constructor called"<< std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat : " << type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called"<< std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Maow" << std::endl;
}
