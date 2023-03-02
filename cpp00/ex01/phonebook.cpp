#include "phonebook.hpp"

int main()
{
	PhoneBook phone;
	Contact contact;

	phone.repertoire = 1;
	std::cout << "Yo les mec" << phone.repertoire << std::endl;
	contact.set_firstname();
	contact.set_lastname();
	contact.set_nickname();
	contact.set_phonenumber();
	contact.set_darkestsecret();

}
