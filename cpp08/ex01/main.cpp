#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    {
        Span test(7);

        test.addNumber(15);
        test.addNumber(1);
        test.addNumber(-5);
        test.addNumber(0);
        test.addNumber(100);
        test.addNumber(-5564);
        test.addNumber(19);
        try {
            int ret = test.longestSpan();
            std::cout << "The longest distance in the Span is: " << ret << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            int ret = test.shortestSpan();
            std::cout << "The shortest distance in the Span is: " << ret << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        Span test(7);
        std::vector<int> vec;
        for (int i = 0; i < 70; i++)
            vec.push_back(i);
        test.addNumber(vec.begin(), vec.end());
        try {
            int ret = test.longestSpan();
            std::cout << "The longest distance in the Span is: " << ret << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            int ret = test.shortestSpan();
            std::cout << "The shortest distance in the Span is: " << ret << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
