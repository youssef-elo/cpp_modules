#ifndef DIAMOND_HPP
# define DIAMOND_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
	private:
		std::string name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name_arg);
		std::string getname() const;
		DiamondTrap& operator=(const DiamondTrap& other);
		void WhoamI();
		void attack(const std::string &target);
};


#endif