#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{
	private:
		std::string type;
	public:
		Weapon();
		Weapon( std::string arg );
		void setType( std::string arg );
		const std::string& getType( void );
};

#endif