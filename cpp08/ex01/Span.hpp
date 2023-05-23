#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <exception>

class Span{
	public:
		Span(const unsigned int& N);
		Span(const Span &rhs);

		~Span();

		Span& operator=(const Span& rhs);

		void addNumber(int nb);
		void addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		unsigned int shortestSpan(int nb) const;
		unsigned int longestSpan(int nb) const;
		class ContainerFull : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Container full !");
				}
		};

		class ContainerEmpty : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Container Empty !");
				}
		};

	private:
	std::vector<int>	_v;
	unsigned int 	_size;
};
