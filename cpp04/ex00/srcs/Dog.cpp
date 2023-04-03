#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Void Dog has been created :o" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog " << type << " has been created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog is gone" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
