#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	int look_for = 10;
	int arr[] = { 0, 9, 4454, 343, 645, 8,10};
	std::vector<int>::iterator it;
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	it = vec.end();
	try
	{
		it = easyfind(vec, look_for);
		std::cout << "Element " << *it << " was found at index " << (it - vec.begin()) << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cerr << look_for << " " <<  ex.what() << std::endl;
	}

	look_for = -10;
	try
	{
		it = easyfind(vec, look_for);
		std::cout << "Element " << *it << " was found at index " << (it - vec.begin()) << std::endl;
	}
	catch(const std::exception& ex)
	{
		std::cerr << look_for << " " << ex.what() << std::endl;
	}
	return 0;
}
