#ifndef ZOMBIE_HPP
 # define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private: 
		std::string name;
	public:
		void announce( void );
		Zombie();
		Zombie( std::string arg );
		~Zombie();
};

#endif