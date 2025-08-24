#include <iostream>
#include "Array.hpp"

template <typename TYPE>
std::ostream& operator<<( std::ostream& out, const Array<TYPE>& other)
{
	for (unsigned int i = 0 ; i < other.size(); i++)
		out << other[i] << std::endl;
	return out;
}

int main()
{
	Array<float> test;
	try
	{
		std::cout << test[0] << std::endl;
	}
	catch ( const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	Array<int> first(10);

	for ( unsigned int i  = 0 ; i < first.size(); i++)
		first[i] = i;
	
	std::cout << first;

	Array<int> tmp(8);
	Array<int> second(tmp);

	std::cout << std::endl << std::endl << second;
	second = first;
	std::cout << std::endl << std::endl << second << std::endl;
}
