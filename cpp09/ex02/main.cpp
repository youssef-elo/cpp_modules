#include "PmergeMe.hpp"

int main()
{
	PmergeMe sorter;
	int arr[]  = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	std::vector<int> test( arr , arr + (sizeof(arr) / sizeof( arr[0])));
	sorter.sort_numbers(test);
	// std::vector<int> ret = sorter.pmergeme(test);
	// for ( size_t i = 0 ; i < ret.size() ; i++)
	// 	std::cout << (i == 0 ? "": " ") << ret[i];
	// std::sort(test.begin() , test.end());
	// std::cout << std::endl;
	// for ( size_t i = 0 ; i < test.size() ; i++)
	// 	std::cout << (i == 0 ? "": " ") << test[i];
	
	
}
