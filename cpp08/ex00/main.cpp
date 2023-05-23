#include "easyfind.hpp"

void print(int i)
{
	std::cout << i << std::endl;
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found the number at position: " << std::distance(v.begin(), it) << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "Found the number at position: " << std::distance(v.begin(), it) << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
