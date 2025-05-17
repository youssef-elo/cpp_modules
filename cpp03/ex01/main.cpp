#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot1("R2-D2");
	ClapTrap robot2("Z76-D38");

	robot1.attack("Z76-D38");
	robot2.takeDamage(robot1.get_attack_damage());
	robot2.attack("R2-D2");
	robot2.beRepaired(100);
}