#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<double> doubleArray(5);
        std::cout << "Double array size: " << doubleArray.size() << std::endl;

        Array<double> test(doubleArray);
        std::cout << "Copy constructor array size: " << test.size() << std::endl;

        doubleArray[0] = 1.1;
        doubleArray[1] = 2.2;
        doubleArray[2] = 3.3;
        doubleArray[3] = 4.4;
        doubleArray[4] = 5.5;

        for (unsigned int i = 0; i < doubleArray.size(); ++i) {
            std::cout << "Element " << i << ": " << doubleArray[i] << std::endl;
        }

        std::cout << doubleArray[5] << std::endl; // will throw an exception

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}