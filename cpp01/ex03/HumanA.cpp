#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& starting_weapon)
{
	name = human_name;
	weapon = &starting_weapon;
}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
