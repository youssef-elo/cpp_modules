#include "ClapTrap.hpp"

std::string ClapTrap::getname() const
{
	return name;
}

unsigned int ClapTrap::get_hit_points() const
{
	return hit_points;
}

unsigned int ClapTrap::get_energy_points() const
{
	return energy_points;
}

unsigned int ClapTrap::get_attack_damage() const
{
	return attack_damage;
}

ClapTrap::ClapTrap() : name("default_clap_name"),
					   hit_points(10),
					   energy_points(10),
					   attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name_arg) : name(name_arg + "_clap_name"),
										   hit_points(10),
										   energy_points(10),
										   attack_damage(0)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other) : name(other.getname()),
											hit_points(other.get_hit_points()),
											energy_points(other.get_energy_points()),
											attack_damage(other.get_attack_damage())
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	name = other.getname();
	hit_points = other.get_hit_points();
	energy_points = other.get_energy_points();
	attack_damage = other.get_attack_damage();
	std::cout << "ClapTrap Copy assignement operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is self destructing" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount){
	if (amount > 0 && amount >= hit_points)
	{
		hit_points = 0;
		std::cout << "ClapTrap " << name << " took damage current health is: " << hit_points << std::endl;
	}
	else if (amount > 0 && hit_points > 0)
	{
		hit_points -= amount;
		std::cout << "ClapTrap " << name << " took damage current health is: " << hit_points << std::endl;
	}
	else if (!hit_points)
		std::cout << "ClapTrap " << name << " has no health left" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no more energy points it cannot attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	long long test = amount + hit_points;

	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no more energy points it cannot heal" << std::endl;
		return ;
	}
	if (test > UINTMAX_)
		hit_points = UINTMAX_;
	else 
		hit_points += amount;
	std::cout << "ClapTrap " << name << " is healing current health is: " << hit_points << std::endl;
	energy_points--;
}
