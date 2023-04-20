#ifndef DATA_HPP
#define DATA_HPP
#include <string>
#include <cstdint>
#include <iostream>
struct Data{
    int a;
    double b;
    float c;
    int age;

};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
#endif