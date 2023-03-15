#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <functional>

class Harl{
	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);


	public:
	void complain( std::string level );
};

typedef void (Harl::*MemFuncPtr)();

#endif
