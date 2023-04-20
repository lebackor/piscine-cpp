#include "Data.hpp"

int main() {
    Data obj;
    obj.a = 42;
    obj.b = 3.14;

    std::cout << "Original variables:" << std::endl;
    std::cout << "a: " << obj.a << std::endl;
    std::cout << "b: " << obj.b << std::endl;

    uintptr_t serialized = serialize(&obj);
    Data* deserialized = deserialize(serialized);

    std::cout << "Converted variables:" << std::endl;
    std::cout << "a: " << deserialized->a << std::endl;
    std::cout << "b: " << deserialized->b << std::endl;

    if (&obj == deserialized)
        std::cout << "Both adress are the same" << std::endl;
    else
        std::cout << "Error, differents address" << std::endl;
    return 0;
}
