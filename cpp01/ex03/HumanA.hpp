#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
# include <string>

class HumanA{
	private:
		Weapon *weapon;
		std::string name;
	public:
		void attack( void );
		HumanA(std::string human_name, Weapon& starting_weapon);
};

#endif