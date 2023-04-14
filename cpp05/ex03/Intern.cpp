#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
Intern::Intern(){}

Intern::~Intern(){}

Form* Intern::makeForm(const std::string& nameform, const std::string& target) const
{
    Form* tmp = NULL;
    std::string namesForm[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i = 0;
	while (i < 3 && namesForm[i] != nameform)
        i++;
    switch (i)
    {
        case 0:
            tmp = new RobotomyRequestForm(target);
            break;
        case 1:
            tmp = new PresidentialPardonForm(target);
            break;
        case 2:
            tmp = new ShrubberyCreationForm(target);
            break;
        default:
            throw Intern::NotRecognizedInputException();
    }
    std::cout << "Intern create " << nameform << " successfully !" << std::endl;
    return tmp;
}