#include "Contact.hpp"

void Contact::set_firstname()
{
	std::cout << GREEN << "Enter first name:" << RESET <<std::endl;
	std::getline(std::cin, this->c_firstname);
	while (this->c_firstname.empty() == true && !std::cin.eof())
	{
		std::cout << RED << "Wrong input, retry please:" << RESET << std::endl;
		std::getline(std::cin, this->c_firstname);
	}
}
void Contact::set_lastname()
{
	std::cout << GREEN << "Enter last name:" << RESET << std::endl;
	std::getline(std::cin, this->c_lastname);
}
void Contact::set_nickname()
{
	std::cout << GREEN << "Enter nick name:" << RESET << std::endl;
	std::getline(std::cin, this->c_nickname);
}
void Contact::set_phonenumber()
{
	std::cout << GREEN << "Enter phone number:" << RESET << std::endl;
	std::getline(std::cin, this->c_phonenumber);
}
void Contact::set_darkestsecret()
{
	std::cout << GREEN << "Enter your darkest secret:" << RESET << std::endl;
	std::getline(std::cin, this->c_darkestsecret);
}

std::string	Contact::get_firstname() const
{
	return	(this->c_firstname);
}

std::string	Contact::get_lastname() const
{
	return	(this->c_lastname);
}

std::string	Contact::get_nickname() const
{
	return	(this->c_nickname);
}

std::string	Contact::get_phonenumber() const
{
	return	(this->c_phonenumber);
}

std::string	Contact::get_darkestsecret() const
{
	return	(this->c_darkestsecret);
}

void	Contact::add_infos()
{
	this->set_firstname();
	this->set_lastname();
	this->set_nickname();
	this->set_phonenumber();
	this->set_darkestsecret();
}
