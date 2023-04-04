#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

int main()
{
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; ++i)
    {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "Les idées du premier chien et du premier chat :" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        std::cout << "Chien " << i << ": " << ((Dog *)animals[0])->getBrain()->getIdeas(i) << std::endl;
        std::cout << "Chat " << i << ": " << ((Cat *)animals[numAnimals / 2])->getBrain()->getIdeas(i) << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < numAnimals; ++i)
    {
        delete animals[i];
    }
}

// #include "Cat.hpp"
// #include "Dog.hpp"
// #include <iomanip>

// int main()
// {
// 	Animal* animals[10];

// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (i >= 5)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}
// 	Cat copy(*(Cat *)animals[0]);
// 	std::cout << std::endl;
// 	for (int i = 0; i < 100; i++)
// 	{
// 		std::cout << std::setw(30) << std::left << copy.getBrain()->getIdeas(i);
// 		std::cout << std::setw(30) << std::left << ((Cat *)animals[0])->getBrain()->getIdeas(i) << std::endl;
// 	}
// 	std::cout << std::endl;
// 	for (int i = 0; i < 10; i++)
// 	{
// 		delete animals[i];
// 	}
// 	// system("leaks Animals");
// }
