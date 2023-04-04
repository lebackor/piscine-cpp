#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat &rhs);
		virtual void makeSound() const;
		Brain* getBrain() const;
	private:
		Brain* _brain;
};

#endif
