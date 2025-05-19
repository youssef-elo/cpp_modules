#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hit_points = 100;
	energy_points = 100;
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
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap " << name << "copy assignement operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "ScavTrap " << name << " is requesting a high five." << std::endl;
}


void FragTrap::attack(const std::string &target)
{
	if (energy_points == 0)
	{
		std::cout << "FragTrap " << name << " has no more energy points it cannot attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}
