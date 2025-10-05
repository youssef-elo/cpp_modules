#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <sstream>
#include <deque>
#include <iomanip> 
#include <cmath>

class PmergeMe {
	private: 
		PmergeMe( const PmergeMe& other);
		PmergeMe& operator=( const PmergeMe& other);

		typedef std::deque<int>::iterator deq_iterator;
		typedef std::vector<int>::iterator vec_iterator;
	
		long getjacob(long n);
		void ford_jhonson_sort_deque(std::deque<int> &nums, int unit_size);
		void ford_jhonson_sort_vector(std::vector<int> &nums, int unit_size);

		template <typename Container>
		bool is_sorted( Container& nums)
		{
			for (size_t i = 1; i < nums.size(); i++)
			{
				if (nums[i] < nums[i - 1])
					return false;
			}
			return true;
		}
		
		template <typename Container>
		void switch_units( Container& nums, int first, int second, int unit_size)
		{
			typename Container::iterator first_it, second_it;
			first_it = nums.begin() + first;
			second_it = nums.begin() + second;
			for ( int i = 0; i < unit_size; i++)
			{
				std::iter_swap(first_it, second_it);
				--first_it;
				--second_it;
			}
		}
	public:
		PmergeMe();
		~PmergeMe();
		void sort_numbers(std::vector<int> nums_vec, std::deque<int> nums_deq);
};

#endif