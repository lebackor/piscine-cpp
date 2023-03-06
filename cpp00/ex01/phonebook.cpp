#include "phonebook.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string str;
	int i = 0;
	int count = 0;
	while (str.compare("EXIT") != 0)
	{
		std::cin >> str;
		if (str.compare("ADD") == 0)
		{
			contact.set_firstname();
			contact.set_lastname();
			contact.set_nickname();
			contact.set_phonenumber();
			contact.set_darkestsecret();
			if (i < 8)
			{
				phonebook.stock_firstname[i] = contact.c_firstname;
				phonebook.stock_lastname[i] = contact.c_lastname;
				phonebook.stock_nickname[i] = contact.c_nickname;
				phonebook.stock_phonenumber[i] = contact.c_phonenumber;
				phonebook.stock_darkestsecret[i] = contact.c_darkestsecret;
				i++;
				count++;
			}
			else
			{
				i = 0;
				phonebook.stock_firstname[i] = contact.c_firstname;
				phonebook.stock_lastname[i] = contact.c_lastname;
				phonebook.stock_nickname[i] = contact.c_nickname;
				phonebook.stock_phonenumber[i] = contact.c_phonenumber;
				phonebook.stock_darkestsecret[i] = contact.c_darkestsecret;
				i++;
			}
		}
		else if (str.compare("SEARCH") == 0)
		{
			for (int j = 0; j < count; j++)
			{
				std::cout << j+1;
				std::cout << "|";
				if (phonebook.stock_firstname[j].length() < 10)
					std::cout << phonebook.stock_firstname[j] << std::setw (10);
				else
					std::cout << phonebook.stock_firstname[j] << std::setfill('.') << std::setw (1); // HAVE TO FIX THIS
				std::cout << "|";
				std::cout << phonebook.stock_lastname[j] << std::setw (10);
				std::cout << "|";
				std::cout << phonebook.stock_nickname[j] << std::setw (10);
				std::cout << "|";
				std::cout << phonebook.stock_phonenumber[j] << std::setw (10);
				std::cout << std::endl;
			}
		}
	}

}
