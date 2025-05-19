#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap robot2("Z76-D38");
	DiamondTrap robot1("R2-D2");

	std::cout << std::endl;
	std::cout << std::endl;
	robot1.attack("Z76-D38");
	robot2.takeDamage(robot1.get_attack_damage());
	robot2.attack("R2-D2");
	robot1.takeDamage(robot2.get_attack_damage());
	std::cout << std::endl;
	robot2.highFivesGuys();
	std::cout << std::endl;
	robot2.WhoamI();
	std::cout << std::endl;
}
