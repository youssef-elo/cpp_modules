#include "PmergeMe.hpp"


template<typename Container>
void print_container(const Container& c)
{
	for ( size_t i = 0; i < c.size(); i++)
		std::cout << ( i == 0 ? "" : " ") << c[i];
	std::cout << std::endl;
}



int main()
{
	PmergeMe sorter;

int arr[] = {3, 1, 4};
	// int arr[] = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	// int arr[] = {45, 12, 23, 89, 56, 77, 34, 90, 11, 65, 1000, 540, 2458, 54, 21, 32, 87, 15, 33, 29, 48, 73, 99, 101, 2, 6};
	// int arr[]  = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int arr[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91};
	std::vector<int> test( arr , arr + (sizeof(arr) / sizeof( arr[0])));
	std::vector<int> ret =  sorter.sort_numbers(test);
	if ( sorter.is_sorted(ret) )
	{
		std::cout << "Sorted list in "<< number_of_comparisons << " comparisons" << std::endl;
		for (size_t i = 0; i < ret.size(); i++)
		{
			std::cout << ret[i] << " ";
		}
	}
	else 
		std::cout << " list wasnt sorted " << std::endl;
	
}

