#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public: 
		FragTrap();
        ~FragTrap();
        FragTrap(std::string name_arg);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);

		void highFivesGuys(void);
};

#endif