#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form{
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        void action(const Bureaucrat& executor) const;
        RobotomyRequestForm& operator=(RobotomyRequestForm& rhs);
    private:

};


#endif