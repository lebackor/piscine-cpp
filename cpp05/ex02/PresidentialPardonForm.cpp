#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5, target){}

PresidentialPardonForm::~PresidentialPardonForm(){
    
}

void PresidentialPardonForm::action(const Bureaucrat& executor) const
{
	this->Form::execute(executor);
	std::cout << this->getTarget() << "has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    this->Form::operator=(rhs);
    return (*this);
}
