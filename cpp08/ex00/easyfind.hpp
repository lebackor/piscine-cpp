#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>


template <typename T>
typename T::iterator easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it != container.end())
		return (it);
	else
        throw std::runtime_error("Element not found in container");
}
