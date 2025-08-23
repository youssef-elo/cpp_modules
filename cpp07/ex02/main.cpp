#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> first(20);
	// std::cout << first;
	for ( unsigned int i  = 0 ; i < first.size(); i++)
		first[i] = i;
	std::cout << first;
	Array<int>tmp(8);
	Array<int> second(tmp);

	std::cout << std::endl << std::endl << second;
	second = first;
	std::cout << std::endl << std::endl << second;
}
