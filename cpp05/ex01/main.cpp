#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat john("John", 2);
        Bureaucrat jane("Jane", 1);
        Form formA("Form A", 2, 3);

        std::cout << john << std::endl;
        std::cout << jane << std::endl;
        std::cout << formA << std::endl;

        john.signForm(formA);
        std::cout << formA << std::endl;

        jane.signForm(formA);
        std::cout << formA << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
