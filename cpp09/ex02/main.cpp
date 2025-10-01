#include "PmergeMe.hpp"

bool parse_numbers( char **av, int ac, std::vector<int>& nums_vec, std::deque<int>& nums_deq)
{
	std::stringstream ss;
	int tmp;
	
	for ( int i = 0; i < ac; i++)
	{
		ss << av[i];
		ss >> tmp;
		if ( ss.fail() || !ss.eof() || tmp < 0)
		{
			std::cerr << "Arguments should be a positive integer sequence only digits, only leading white spaces are allowed, no trailing, no negative numbers!" << std::endl;
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
	if ( ac == 1)
	{
		std::cerr << "No arguments!" << std::endl;
		return 1;
	}
	std::vector<int> nums_vec;
	std::deque<int> nums_deq;
	PmergeMe sorter;

	if ( !parse_numbers(av + 1, ac - 1, nums_vec, nums_deq) )
		return 1;
	sorter.sort_numbers(nums_vec, nums_deq);
}
