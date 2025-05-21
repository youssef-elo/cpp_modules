#include "DiamondTrap.hpp"

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::WhoamI()
{
	std::cout << "DiamondTrap name is " << name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap() , FragTrap(), ScavTrap(){
	name = "default";
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other) , ScavTrap(other)
{
	name = other.getname();
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name_arg) : ClapTrap(name_arg) , FragTrap(name_arg), ScavTrap(name_arg){
	name = name_arg;
	std::cout << "DiamondTrap parameterized constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is self destructing." << std::endl;
}

std::string DiamondTrap::getname() const
{
	return name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	ClapTrap::operator=(other);
	name = other.getname();
	return *this;
}
