#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe {
	private:

	public:
		// PmergeMe();
		// ~PmergeMe();
		// PmergeMe(const PmergeMe& other);
		// PmergeMe& operator=(const PmergeMe& other);
		std::vector<size_t> jacob_sequence;
		void generate_jacob_sequence( size_t n )
		{
			if ( n < jacob_sequence.size())
				return;
			if ( jacob_sequence.size() < 4)
			{
				jacob_sequence.push_back(0);
				jacob_sequence.push_back(1);
				jacob_sequence.push_back(3);
				jacob_sequence.push_back(5);
			}
			for ( size_t i = jacob_sequence.size(); i < n; i++)
			{
				jacob_sequence.push_back(jacob_sequence[i - 1] + 2 * jacob_sequence[i - 2]);
			}
		}
		void jacob_insertion(std::vector<int>& main_chain, std::vector<int>& pend_chain)
		{
			std::vector<bool> inserted(pend_chain.size(), false);
			std::vector<int>::iterator main_it;
			for ( size_t i = 0; i < jacob_sequence.size(); i++)
			{
				if ( jacob_sequence[i] >= pend_chain.size())
					break;

				int value  = pend_chain[jacob_sequence[i]];
				main_it = std::lower_bound(main_chain.begin(), main_chain.end(), value);
				main_chain.insert(main_it, value);
				inserted[jacob_sequence[i]] = true;
			}
			for ( size_t i = 0; i < pend_chain.size(); i++)
			{
				if ( !inserted[i] )
				{
					main_it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[i]);
					main_chain.insert(main_it, pend_chain[i]);	
				}
			}
		}
		
		std::vector<int> ford_jhonson_sort( std::vector<int> nums)
		{
			int n = nums.size();
			if ( n == 1)
				return nums;
			std::vector<int> pend_chain;
			std::vector<int> main_chain;
			
			/*
				check if the vector has an odd number of elements keep the elements 
				and set the flag to true so it is added to the main chain when it is formed
			*/
			bool odd_exists = false;
			int odd_element; 
			if ( n % 2 != 0)
			{
				n--;
				odd_exists = true;
				odd_element = nums[nums.size() - 1];
				nums.pop_back();
			}
			for ( int i = 1; i < n; i+=2)
			{
				if ( nums[i] > nums[i - 1])
				{
					main_chain.push_back(nums[i]);
					pend_chain.push_back(nums[i - 1]);
				}
				else if ( nums[i] <= nums[i - 1])
				{
					main_chain.push_back(nums[i - 1]);
					pend_chain.push_back(nums[i]);
				}
			}
			//add the last element of the incoming vector if it was odd sized
			if ( odd_exists )
				main_chain.push_back(odd_element);
			std::cout << main_chain.size() << " " << pend_chain.size() << std::endl;
			//recurse over the main chain untill it is down to the base case of one element which is sorted
			main_chain = ford_jhonson_sort(main_chain);
			//from the returned sorted main chain insert the pend chain elements into it using the jacob sthall sequence as indexes to which element to push into 
			// the main chain, the insetion is done using binary search 
			jacob_insertion(main_chain, pend_chain);
			//at this point the main_chain is sorted and keeps on return up the stack until it goes back to the first call of ford jhoson and on each return the 
			// corresponding pend chain element of that step are the pushed to the returned array
			return main_chain;
		}
		std::vector<int> pmergeme(std::vector<int>& nums)
		{
			//generate the jacob sthal sequence up to half of the size of the given array since the first iteration of the ford jhonson will split them into two 
			// that means that at most i will need half of the array size in jacob sthall. ( even less since it grows exponentially but whatever).
			generate_jacob_sequence( nums.size() / 2 + 1);
			return ford_jhonson_sort(nums);
		}
};

#endif