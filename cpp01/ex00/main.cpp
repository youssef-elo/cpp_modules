#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie *first = newZombie("heap zombie");
	first->announce();
	randomChump("stack zombie");
	delete first;
}
