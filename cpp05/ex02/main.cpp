#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\033[1;32m---- ShrubberyCreationForm Tests ----\033[0m" << std::endl;

    Bureaucrat james("James", 146);
    ShrubberyCreationForm shrubberyForm("garden");
    james.signForm(shrubberyForm);
    james.executeForm(shrubberyForm);

    std::cout << "\033[1;33m---- RobotomyRequestForm Tests ----\033[0m" << std::endl;

    Bureaucrat emily("Emily", 50);
    RobotomyRequestForm robotomyForm("R2D2");
    emily.signForm(robotomyForm);
    emily.executeForm(robotomyForm);

    std::cout << "\033[1;34m---- PresidentialPardonForm Tests ----\033[0m" << std::endl;

    Bureaucrat jacob("Jacob", 20);
    PresidentialPardonForm presidentialForm("Alice");
    jacob.signForm(presidentialForm);
    jacob.executeForm(presidentialForm);

    std::cout << "\033[1;35m---- Form Error Tests ----\033[0m" << std::endl;

    Bureaucrat alice("Alice", 1);
    ShrubberyCreationForm shrubberyForm2("Grass");
    alice.signForm(shrubberyForm2);
    alice.executeForm(shrubberyForm2);

    return 0;
}
