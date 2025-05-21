#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap robot1("R2-D2");
	ScavTrap robot2("Z76-D38");

	std::cout << std::endl;
	robot1.attack("Z76-D38");
	robot2.attack("R2-D2");
	robot2.guardGate();
	robot2.guardGate();
	std::cout << std::endl;
}