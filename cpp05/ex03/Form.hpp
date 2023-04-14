#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:
	Form();
	Form(std::string name, const unsigned int gradeSign, const unsigned int gradeExec);
	Form(std::string name,const unsigned int gradeSign, const unsigned int gradeExec, std::string target);
	Form(const Form& other);
	virtual ~Form();

	Form& operator=(const Form& rhs);


	//getters
	std::string getName() const;
	unsigned int getGradeSign() const;
	unsigned int getGradeExec() const;
	std::string getTarget() const;
	bool isSigned() const;


	void	execute(Bureaucrat const & executor) const;
	virtual void action(Bureaucrat const & executor) const = 0;
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
	class AlreadySignException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Form is already sign!");
			}
	};	
	class FormNotSigned : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Form is not signed!");
			}
	};
	private:
		const std::string _name;
		const unsigned int _gradeSign;
		const unsigned int _gradeExec;
		bool _isSigned;
	    std::string _target;

};

std::ostream& operator<<(std::ostream &o, const Form& rhs);

#endif
