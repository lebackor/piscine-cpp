#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cctype>

class PhoneBook{
	public:
	int repertoire;
		PhoneBook(){
			repertoire = 0;
			repertoire += 1;
			// int number[10];
		}
		~PhoneBook(){

		}
};

class Contact{
	private:
		std::string c_firstname;
		std::string c_lastname;
		std::string c_nickname;
		std::string c_phonenumber;
		std::string c_darkestsecret;
	public:
		void set_firstname()
		{
			std::cout << "Enter first name:" << std::endl;
			std::cin >> c_firstname;
		}
		void set_lastname()
		{
			std::cout << "Enter last name:" << std::endl;
			std::cin >> c_lastname;
		}
		void set_nickname()
		{
			std::cout << "Enter nick name:" << std::endl;
			std::cin >> c_nickname;
		}
		void set_phonenumber()
		{
			std::cout << "Enter phone number:" << std::endl;
			std::cin >> c_phonenumber;
		}
		void set_darkestsecret()
		{
			std::cout << "Enter your darkest secret:" << std::endl;
			std::cin >> c_darkestsecret;
		}
};
#endif
