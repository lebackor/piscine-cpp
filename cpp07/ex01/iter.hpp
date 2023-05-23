#pragma once
#include <string>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*f)(const T&))
{
	for (size_t i = 0; i < length; i++)
		(*f)(array[i]);
}

template <typename T>
void printElement(const T& a)
{
	std::cout << a << std::endl;
}
