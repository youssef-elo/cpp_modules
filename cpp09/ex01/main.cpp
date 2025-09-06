#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	RPN claculator;

	if ( ac != 2)
	{
		std::cerr << "Program takes one string, the rpn expression." << std::endl;
		return 1;
	}
	std::string tmp(av[1]);
	try {
		std::cout << claculator.calculate(tmp) << std::endl;
	}
	catch ( const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
