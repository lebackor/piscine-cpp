#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Weapon{
	private:
	std::string _type;


	public:
	const std::string &getType() const;
	void  setType(std::string type);
	Weapon(std::string _type) : _type(_type){

	}
	~Weapon()
	{

	}
};

#endif
