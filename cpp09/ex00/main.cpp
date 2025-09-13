#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
	if ( ac != 2)
	{
		std::cerr << "Program takes one file name to read input from." << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange trader;
		trader.read_file(av[1]);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
