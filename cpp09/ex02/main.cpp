#include "PmergeMe.hpp"

int main()
{
	PmergeMe sorter;
	int arr[]  = { 6, 7, 9, 10, 11, 21, 22, 27, 28, 35, 36, 37};
	std::vector<int> test( arr , arr + (sizeof(arr) / sizeof( arr[0])));
	std::vector<int> ret = sorter.pmergeme(test);
	for ( size_t i = 0 ; i < ret.size() ; i++)
		std::cout << (i == 0 ? "": " ") << ret[i];
	std::sort(test.begin() , test.end());
	std::cout << std::endl;
	for ( size_t i = 0 ; i < test.size() ; i++)
		std::cout << (i == 0 ? "": " ") << test[i];
	
	
}

 