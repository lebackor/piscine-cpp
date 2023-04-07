#include "Form.hpp"

Form::Form() : _name(""), _gradeSign(1), _gradeExec(1), _isSigned(false){}

Form::Form(std::string name, const unsigned int gradeSign, const unsigned int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _isSigned(false)
{
	if (gradeExec < 1 || gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeExec > 150 || gradeSign > 150)
		throw Form::GradeTooLowException();

}

Form::Form(const Form& other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec), _isSigned(other._isSigned)
{}

Form::~Form(){}


Form& Form::operator=(const Form& rhs)
{
	(void) rhs;
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

unsigned int Form::getGradeSign() const
{
	return this->_gradeSign;
}

unsigned int Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool Form::isSigned() const
{
	return this->_isSigned;
}

void Form::beSigned(const Bureaucrat& candidat)
{
	if (!this->_isSigned)
		if (candidat.getGrade() < this->_gradeSign)
			this->_isSigned = true;
		else
			throw Form::GradeTooLowException();
	else
		throw Form::AlreadySignException();
}

std::ostream& operator<<(std::ostream& o, const Form& rhs)
{
	o << "Form " << rhs.getName() << ": ";
	o << "{signed: " << std::boolalpha << rhs.isSigned() << ", gradeSign: " << rhs.getGradeSign() << ", gradeExec: " << rhs.getGradeExec() << "}";
	return o;
}
