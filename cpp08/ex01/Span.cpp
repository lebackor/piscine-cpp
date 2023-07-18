#include "Span.hpp"


Span::Span() : _size(0)
{

}

Span::Span(const unsigned int& N) : _size(N)
{
}

Span::Span(const Span &rhs) : _size(rhs._size), _v(rhs._v)
{}


Span& Span::operator=(const Span& rhs)
{
    _size = rhs._size;
    _v.clear();
    for (std::vector<int>::const_iterator it = rhs._v.begin(); it != rhs._v.end(); it++)
        _v.push_back(*it);
    return *this;
}

Span::~Span()
{

}


void Span::addNumber(int nb)
{
	try
	{
		if (_v.size() < _size)
		{
			_v.push_back(nb);
			std::cout << nb << " has been added to the span" << std::endl;
		}
		else
			throw SpanFull();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

}

void Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	try
	{
		for (std::vector<int>::iterator it = begin; it != end; it++)
		{
			if (_v.size() < _size)
			{
				_v.push_back(*it);
				std::cout << *it << " has been added to the span" << std::endl;
			}
			else
				throw SpanFull();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

unsigned int Span::shortestSpan() {

    if (_v.size() > 1) {
        std::sort(_v.begin(), _v.end());
        int min = *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
        int tmp;
        for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++) {
            if (it != _v.begin() && abs(*it - tmp) < min)
                min = abs(*it - tmp);
            tmp = *it;
        }
        return min;
    } else {
        throw Span::NotEnoughtNumber();
    }
}
unsigned int Span::longestSpan() {
    if (_v.size() > 1)
        return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
    else
        throw Span::NotEnoughtNumber();
}