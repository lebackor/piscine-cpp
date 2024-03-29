#ifndef CONVERT_HPP
#define CONVERT_HPP
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

# include <iostream>
# include <string>
# include <stdlib.h>
# include <iomanip>
# include <limits>
# include <string.h>


class Convert{
	public:
		Convert(std::string str);
		~Convert();
		void catch_and_convert();
		 bool content_point(const std::string& s);
		 bool content_letters(const std::string& s);
		 bool content_number(const std::string& s);
		bool check_if_float(const std::string& s);
		bool good_float_synthax(const std::string &s);
		int isstrValid(std::string str, std::string type);
		void toInt();
		void toFloat();
		void toDouble();
		void toChar();
	class IDKType : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Invalid input ! : Cannot recognized at all the type");
		}
	};
	private:
		std::string _value;
		// int			_intvalue;
		// float		_floatvalue;
		// double		_doublevalue;
		// char		_charvalue;

};

#endif
