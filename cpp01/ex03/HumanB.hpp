#ifndef HumanB_HPP
# define HUMAN_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>
class HumanB{
	private:
		std::string name_;
		Weapon *weapon_;
	public:
		void attack( void );
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
};

#endif