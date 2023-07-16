#pragma once

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array
{
    public:
        Array() : _size(0), _array(new T[0]){};
        Array(unsigned int n) : _size(n), _array(new T[n]){};
        Array(const Array& other)
        {
            this->_size = other._size;
            this->_array = new T[other._size];
            for (unsigned int i = 0; i < other._size; i++)
                this->_array[i] = other._array[i];
        }
        ~Array()
        {
            delete [] this->_array;
        }

        Array& operator=(const Array& rhs)
        {
            if (this != &rhs)
            {
                // this->~Array();
                delete [] this->_array;
                this->_size = rhs._size;
                this->_array = new T[rhs._size];
                for (unsigned int i = 0; i < rhs._size; i++)
                    this-_array[i] = rhs._array[i];
            }
            return *this;
        }

		class TooHightIndex : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Out of range of array");
				}
		};

        T& operator[](unsigned int i)
        {
            if (i >= this->_size)
				throw TooHightIndex();
			return this->_array[i];
        }

		unsigned int size()
		{
			return (this->_size);
		}

    private:
        unsigned int _size;
        T* _array;
};