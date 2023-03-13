#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
// class Contact;

class PhoneBook{
	private:
		std::string stock_firstname[10];
		std::string stock_lastname[10];
		std::string stock_nickname[10];
		std::string stock_phonenumber[10];
		std::string stock_darkestsecret[10];
	public:
		PhoneBook(){

		}
		~PhoneBook(){

		}
		void	add_data_to_contact(int i, Contact contact);
		void	get_contact_data(int i)const;
		void	get_all_contact_data(int count)const;
};


#endif
