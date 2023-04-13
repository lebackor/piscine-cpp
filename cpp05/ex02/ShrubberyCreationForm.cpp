#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137, target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    
}


void ShrubberyCreationForm::action(const Bureaucrat& executor) const
{
	this->Form::execute(executor);
    std::ofstream outfile(this->getTarget() + "_shrubbery");
    if (!outfile.is_open())
    {
        std::perror("Error while opening the file");
        throw std::runtime_error("Error while opening the file");
    }
  outfile << "       v            /\\            *\n"
          << "      >X<          //\\\\          /|\\\n"
          << "       A          ///\\\\\\        /*|O\\\n"
          << "      d$b        ////\\\\\\\\      /*/|\\*\\\n"
          << "    .d\\$$b.    /////\\\\\\\\\\\n"
          << "  .d$i$$\\$$b.       ||\n"
          << "     d$$$@b         ||\n"
          << "    d$@$$$b         ||\n"
          << "  .d$$$i$$$@b.     ~~~~~\n"
          << "     ###\n"
          << "     ###\n"
          << "     ###\n";

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
    this->Form::operator=(rhs);
    return *this;
}