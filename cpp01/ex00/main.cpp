#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie *first = newZombie("heap zombie");
	if (!first)
	{
		std::cout << "Cannot allocate object" << std::endl;
		return 1;
	}
	first->announce();
	randomChump("stack zombie");
	delete first;
	return 0;
}
