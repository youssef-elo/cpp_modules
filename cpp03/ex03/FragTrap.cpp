#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hit_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is self destructing" << std::endl;
}

FragTrap::FragTrap(std::string name_arg) : ClapTrap(name_arg) 
{
	hit_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return *this;
	std::cout << "FragTrap " << name << "copy assignement operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "ScavTrap " << name << " is requesting a high five." << std::endl;
}

