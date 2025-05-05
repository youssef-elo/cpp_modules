#include "Zombie.hpp"
Zombie *zombieHorde( int N, std::string name );

int main()
{
    Zombie *zombiiies = zombieHorde(10, "Twam");
    for(int i = 0;i < 10; i++)
    {
        zombiiies[i].announce();
    }
    delete[] zombiiies;
}
 