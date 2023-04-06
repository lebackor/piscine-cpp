#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& rhs);

		std::string getName() const;
		unsigned int getGrade() const;


		void incrementeGrade();
		void decrementeGrade();

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
		int _grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
