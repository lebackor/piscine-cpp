#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Void cat has been created" << std::endl;
}

Cat::Cat(std::string type) : Animal(type), _brain(new Brain())
{
	std::cout << "Cat " << type << " has been created" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Meow cat has been kidnapped" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
	return *this;
}


void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->_brain;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
