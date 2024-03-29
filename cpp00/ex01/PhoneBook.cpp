#include "PhoneBook.hpp"


void	PhoneBook::add_data_to_contact(int i, Contact contact)
{
	this->stock_firstname[i] = contact.get_firstname();
	this->stock_lastname[i] = contact.get_lastname();
	this->stock_nickname[i] = contact.get_nickname();
	this->stock_phonenumber[i] = contact.get_phonenumber();
	this->stock_darkestsecret[i] = contact.get_darkestsecret();
}


void	PhoneBook::get_contact_data(int i) const
{
	std::cout << "first name:" << this->stock_firstname[i - 1] << std::endl;
	std::cout << "last name:" << this->stock_lastname[i - 1] << std::endl;
	std::cout << "nick name:" << this->stock_nickname[i - 1] << std::endl;
	std::cout << "phone number:" << this->stock_phonenumber[i - 1] << std::endl;
	std::cout << "darkest secret:" << this->stock_darkestsecret[i - 1] << std::endl;
}

void	PhoneBook::get_all_contact_data(int count) const
{
	for (int j = 0; j < count; j++)
	{
		std::cout << j + 1;
		std::cout << "|";
		if (this->stock_firstname[j].length() >= 10)
			std::cout << this->stock_firstname[j].substr(0, 9) << ".";
		else
			std::cout << this->stock_firstname[j];
		std::cout << "|";
		if (this->stock_lastname[j].length() >= 10)
			std::cout << this->stock_lastname[j].substr(0, 9) << ".";
		else
			std::cout << this->stock_lastname[j];
		std::cout << "|";
		if (this->stock_nickname[j] .length() >= 10)
			std::cout << this->stock_nickname[j] .substr(0, 9) << ".";
		else
			std::cout << this->stock_nickname[j];
		std::cout << std::endl;
	}
}
