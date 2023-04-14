#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45, target)
{

}

RobotomyRequestForm::~RobotomyRequestForm(){

}

void RobotomyRequestForm::action(const Bureaucrat& executor) const
{
    this->Form::execute(executor);
    std::cout << "BzZzZz...... BzZzZzZz......... BzZzZzZzZzZz.........." << std::endl;
    bool reussite = std::rand() % 2;
    if (reussite)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy of " << this->getTarget() << " has failed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
    this->Form::operator=(rhs);
    return *this;
}