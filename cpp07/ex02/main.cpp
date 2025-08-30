#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

template <typename TYPE>
std::ostream &operator<<(std::ostream &out, const Array<TYPE> &other)
{
	for (unsigned int i = 0; i < other.size(); i++)
		out << other[i] << std::endl;
	return out;
}

int main()
{
	{
		Array<float> test;
		std::cout << "Testing out of bounds exception throwing: " << std::endl
				  << std::endl;
		try
		{
			std::cout << test[0] << std::endl;
		}
		catch (const std::exception &ex)
		{
			std::cerr << ex.what() << std::endl
					  << std::endl;
		}

		Array<int> first(10);

		for (unsigned int i = 0; i < first.size(); i++)
			first[i] = i;

		std::cout << "Testing parameterized constructor and [] operator :" << std::endl
				  << first;

		Array<int> tmp(8);
		Array<int> second(tmp);

		std::cout << std::endl
				  << "Testing copy constructor :" << std::endl
				  << second;
		second = first;
		std::cout << std::endl
				  << "Testing copy assignement operator :" << std::endl
				  << second << std::endl;
	}

	std::cout << "Intra tests" << std::endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete[] mirror; //
}
