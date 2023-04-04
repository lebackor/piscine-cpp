#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Void Dog has been created :o" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain())
{
	std::cout << "Dog " << type << " has been created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called on " << other._type << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog is gone" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
}


void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
