#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
	if ( ac != 2)
		return 1;
	BitcoinExchange test;
	test.read_file(av[1]);
}