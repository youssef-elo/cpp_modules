#include "PmergeMe.hpp"

template<typename Container>
void print_container(const Container& c)
{
	for ( size_t i = 0; i < c.size(); i++)
		std::cout << ( i == 0 ? "" : " ") << c[i];
	std::cout << std::endl;
}


bool parse_numbers( char **av, int ac, std::vector<int>& nums_vec, std::deque<int>& nums_deq)
{
	std::stringstream ss;
	int tmp;
	std::string stmp;
	
	for ( int i = 0; i < ac; i++)
	{
		ss << av[i];
		ss >> tmp;
		if ( ss.fail() || !ss.eof() || tmp < 0)
		{
			std::cerr << "Arguments should be a positive sequence only digits, no negative numbers !" << std::endl;
			return false;
		}
		nums_vec.push_back(tmp);
		nums_deq.push_back(tmp);
		ss.clear();
	}
	return true;
}

int main(int ac, char **av)
{
	std::vector<int> nums_vec;
	std::deque<int> nums_deq;
	PmergeMe sorter;

	if ( !parse_numbers(av + 1, ac - 1, nums_vec, nums_deq) )
		return 1;
	
	// int arr[] = {3, 1, 4};
	// int arr[] = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	// int arr[] = {45, 12, 23, 89, 56, 77, 34, 90, 11, 65, 1000, 540, 2458, 54, 21, 32, 87, 15, 33, 29, 48, 73, 99, 101, 2, 6};
	// int arr[]  = { 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	// int arr[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91};
	// std::vector<int> test( arr , arr + (sizeof(arr) / sizeof( arr[0])));
	// std::vector<int> ret =  sorter.sort_numbers(test);
	sorter.sort_numbers(nums_vec, nums_deq);
	
}
