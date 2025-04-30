#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string arg)
{
	name = arg;
}

Zombie::~Zombie()
{
	std::cout << "killing zombie " << name << std::endl;
}

Zombie::Zombie(){}