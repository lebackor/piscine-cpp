#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    void action(const Bureaucrat& executor) const;
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& rhs);
	// class FormWithoutTarget : public std::exception
	// {
	// 	public:
	// 		const char* what() const throw()
	// 		{
	// 			return ("Cannot be create because you need to put a target !");
	// 		}
	// };

    private:


};

#endif