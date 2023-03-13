#ifndef CONTACT_HPP
#	define CONTACT_HPP
#pragma once
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Contact{
	private:
		std::string c_firstname;
		std::string c_lastname;
		std::string c_nickname;
		std::string c_phonenumber;
		std::string c_darkestsecret;

		int	_valid_number();
	public:
		void	set_firstname();
		void	set_lastname();
		void	set_nickname();
		void	set_phonenumber();
		void	set_darkestsecret();
		void	add_infos();

		std::string		get_firstname() const;
		std::string		get_lastname() const;
		std::string		get_nickname() const;
		std::string		get_phonenumber() const;
		std::string		get_darkestsecret() const;

};
#endif
