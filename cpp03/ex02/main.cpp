#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap robot2("Z76-D38");
	FragTrap robot1("R2-D2");

	std::cout << std::endl;
	robot1.attack("Z76-D38");
	robot2.attack("R2-D2");
	robot2.highFivesGuys();
	std::cout << std::endl;
}
