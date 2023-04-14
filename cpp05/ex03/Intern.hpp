#ifndef INTERN_HPP
#define INTERN_HPP

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Form;

class Intern {
    public:
        Intern();
        virtual ~Intern();
        Form* makeForm(const std::string& nameform, const std::string& target) const;
	class NotRecognizedInputException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Not recognized input.");
			}
	};
    private:

};

#endif
