#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	energy_points = 50;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}

ScavTrap::ScavTrap(std::string name_arg) : ClapTrap(name_arg) {
	energy_points = 50;
	std::cout << "ScavTrap Parameteried constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is self destructing" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
	std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " has no more energy points it cannot attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}
