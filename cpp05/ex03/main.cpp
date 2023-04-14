#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{
	srand(time(NULL));

	Bureaucrat john("John", 5);
	Bureaucrat jim("Jim", 45);
	Bureaucrat jane("Jane", 137);

	std::cout << john << std::endl;
	std::cout << jim << std::endl;
	std::cout << jane << std::endl;

	Intern *intern = NULL;

	Form* formA;
	Form* formB;
	Form* formC;
    std::string home = "home";
    std::string PLK = "PLK";
    std::string Chirac = "Chirac";
	try
	{
		formA = intern->makeForm("shrubbery creation", home);
		formB = intern->makeForm("robotomy request", PLK);
		formC = intern->makeForm("presidential pardon", Chirac);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	john.executeForm(*formA);
	jim.executeForm(*formA);
	jane.executeForm(*formA);
	std::cout << std::endl;
	john.signForm(*formA);
	jim.signForm(*formA);
	jane.signForm(*formA);
	std::cout << std::endl;
	john.executeForm(*formA);
	jim.executeForm(*formA);
	jane.executeForm(*formA);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(*formB);
	jim.executeForm(*formB);
	jane.executeForm(*formB);
	std::cout << std::endl;
	john.signForm(*formB);
	jim.signForm(*formB);
	jane.signForm(*formB);
	std::cout << std::endl;
	john.executeForm(*formB);
	jim.executeForm(*formB);
	jane.executeForm(*formB);
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	john.executeForm(*formC);
	jim.executeForm(*formC);
	jane.executeForm(*formC);
	std::cout << std::endl;
	john.signForm(*formC);
	jim.signForm(*formC);
	jane.signForm(*formC);
	std::cout << std::endl;
	john.executeForm(*formC);
	jim.executeForm(*formC);
	jane.executeForm(*formC);

    delete formA;
    delete formB;
    delete formC;
}
