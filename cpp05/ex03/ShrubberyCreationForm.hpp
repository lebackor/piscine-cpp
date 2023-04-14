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
    private:


};

#endif