#include "Harl.hpp"

std::string Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void (Harl::* Harl::methods[4])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

void Harl::debug()
{
	std::cout << "Debuging message"<< std::endl;
}

void Harl::info()
{
	std::cout << "Harl has four levels of annoying messages" << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING!!!!!!!" << std::endl;
}

void Harl::error()
{
	std::cout << "Error Message" << std::endl;
}

void Harl::complain( std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*methods[i])();
	} 
}
