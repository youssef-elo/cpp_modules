#include "Harl.hpp"

int get_level(std::string str)
{
	static std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for ( int i =0; i < 4; i++)
	{
		if (levels[i] == str)
			return (i);
	}
	return (-1);
}

int main(int ac, char **av)
{
	Harl subject;

	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	int level = get_level(av[1]);
    switch (level)
    {
        case -1: 
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break ;
        }
        default :
        {
            subject.list(level);
            break ;
        }
    }
}
