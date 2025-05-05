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
	for (; level < 4; level++)
	{
		switch (level)
		{
			case 0:
				subject.complain("DEBUG");
				break ;
			case 1:
				subject.complain("INFO");
				break ;
			case 2:
				subject.complain("WARNING");
				break ;
			case 3:
				subject.complain("ERROR");
				break ;
			default: 
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return (0);
		}
	}
}
