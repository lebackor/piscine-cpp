#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <exception>

class Span{
	public:
		Span();
		Span(const unsigned int& N);
		Span(const Span &rhs);

		~Span();

		Span& operator=(const Span& rhs);

		void addNumber(int nb);
		void addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		unsigned int shortestSpan() ;
		unsigned int longestSpan() ;
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
		class SpanFull : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("The span is full");
				}
		};		
		
		class NotEnoughtNumber : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Not enought number in the vector");
				}
		};

	private:
	unsigned int 	_size;
	std::vector<int>	_v;
};
