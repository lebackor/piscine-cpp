#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
class Brain
{
public:

	Brain();
	Brain(const Brain& other);

	Brain& operator=(const Brain& rhs);

	~Brain();

	const std::string& getIdeas(int index) const;


private:

	std::string _ideas[100];
};

#endif
