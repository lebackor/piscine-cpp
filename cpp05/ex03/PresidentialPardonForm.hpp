#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form {
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        void action(const Bureaucrat& executor) const;
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    private:

};

#endif