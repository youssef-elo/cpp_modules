#include "Zombie.hpp"

int main()
{
	Zombie *first = new Zombie("heap zombie");
	Zombie second("stack zombie");
	first->announce();
	second.announce();
	delete first;
}
