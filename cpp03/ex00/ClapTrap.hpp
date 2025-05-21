#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define UINTMAX_ 4294967295U

class ClapTrap
{
private:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name_arg);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getname() const;
	unsigned int get_hit_points() const;
	unsigned int get_energy_points() const;
	unsigned int get_attack_damage() const;
};

#endif