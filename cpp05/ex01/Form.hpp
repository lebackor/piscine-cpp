#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
	Form();
	Form(std::string name, const unsigned int gradeSign, const unsigned int gradeExec);
	Form(const Form& other);
	~Form();

	Form& operator=(const Form& rhs);


	//getters
	std::string getName() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExec() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& candidat);
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Grade too high !");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Grade too low !");
			}
	};
	private:
	const std::string _name;
	const unsigned int _gradeSign;
	const unsigned int _gradeExec;
	bool _isSigned;
};

std::ostream& operator<<(std::ostream &o, const Form& rhs);

#endif
