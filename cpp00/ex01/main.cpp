#include "PhoneBook.hpp"

int main()
{
	Contact contact;
	PhoneBook phonebook;
	std::string str;
	std::string index;

	int i = 0;
	int count = 0;/// std.empty == true // !std::cin.eof()
	std::cout << BLUE << "Welcome to PhoneBook !" << "☎️" << RESET << std::endl;
	std::cout << BOLDGREEN << "Choose:	1. ADD	2. SEARCH	3. EXIT" << RESET << std::endl;
	while (str.compare("EXIT") != 0)
	{
		std::getline(std::cin, str);
		if (str.compare("EXIT") == 0)
			return (1);
		if (str.compare("ADD") == 0)
		{
			contact.add_infos();
			if (i <= 7 && count != 7)
			{
				phonebook.add_data_to_contact(i, contact);
				i++;
				count++;
			}
			else if (count == 7 && i != 7)
			{
				phonebook.add_data_to_contact(i, contact);
				i++;
			}
			else
			{
				i = 0;
				phonebook.add_data_to_contact(i, contact);
				i++;
			}
		}
		else if (str.compare("SEARCH") == 0)
		{
			phonebook.get_all_contact_data(count);
			std::cout << "Enter an index" << std::endl;
			// std::cin >> index;
			std::getline(std::cin, index);
			if ((std::atoi(index.c_str()) >= 1 && std::atoi(index.c_str()) <= 8) && std::atoi(index.c_str()) <= count)
			{
				phonebook.get_contact_data(i);
			}
			else
				std::cout << RED << "Bad argument, exiting..." << RESET << std::endl;
		}
		else
			std::cout << BOLDRED << "Input not recognized, try again." << RESET << std::endl;
	}

}
