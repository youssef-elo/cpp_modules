#ifndef ZOMBIE_HPP
 # define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	private: 
		std::string name;
	public:
		~Zombie();
		void announce( void );
		Zombie( std::string arg );
};

#endif