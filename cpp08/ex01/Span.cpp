#include "Span.hpp"


Span::Span(const unsigned int& N) : _size(N)
{
}

Span::Span(const Span &rhs) : _size(rhs._size), _v(rhs._v)


Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_v = rhs._v;
	}
	return this;
}

Span::~Span()
{

}
