#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        void guardGate();
        void attack(const std::string &target);
 
};

#endif