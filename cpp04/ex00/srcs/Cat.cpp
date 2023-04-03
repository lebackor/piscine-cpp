#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Void cat has been created" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat " << type << " has been created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Meow cat has been kidnapped" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}
