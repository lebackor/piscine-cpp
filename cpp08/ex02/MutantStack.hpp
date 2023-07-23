#pragma once

#include <stack>
#include <iostream>

template <class T>

class MutantStack : public std::stack<T>{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack(){};
        MutantStack(MutantStack const &rhs)
        {
            *this = rhs;
        }
        ~MutantStack(){}

        MutantStack& operator=(MutantStack const &rhs)
        {
            this->c = rhs->c();
            return *this;
        }

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }

};

