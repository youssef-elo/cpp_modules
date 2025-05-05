#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl{
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static std::string levels[4];
		static void (Harl::*methods[4])(void);
	public:
		void complain( std::string level);
		void list( int index );
};

#endif