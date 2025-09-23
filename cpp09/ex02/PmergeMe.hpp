#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int number_of_comparisons = 0 ;

bool less_then(int l, int r)
{
	number_of_comparisons++;
	return l < r;
}
bool greater_then(int l, int r)
{
	number_of_comparisons++;
	return l > r;
}


class PmergeMe {
	private:
		typedef std::vector<int>::iterator vec_iterator;
	public:
		
		static int number_of_comparisons;
		std::vector<size_t> jacob_sequence;

		bool is_sorted( std::vector<int>& nums)
		{
			for (size_t i = 1; i < nums.size(); i++)
			{
				if (nums[i] < nums[i - 1])
					return false;
			}
			return true;
		}

		void generate_jacob_sequence( size_t n )
		{
			if ( n < jacob_sequence.size())
				return;
			if ( jacob_sequence.size() < 3)
			{
				jacob_sequence.push_back(3);
				jacob_sequence.push_back(5);
				jacob_sequence.push_back(11);
			}
			for ( size_t i = jacob_sequence.size(); i < n; i++)
			{
				jacob_sequence.push_back(jacob_sequence[i - 1] + 2 * jacob_sequence[i - 2]);
			}
		}
		
		void switch_units(std::vector<int>& nums, int first, int second, int unit_size)
		{
			vec_iterator first_it, second_it;
			first_it = nums.begin() + first;
			second_it = nums.begin() + second;
			for ( int i = 0; i < unit_size; i++)
			{
				std::iter_swap(first_it, second_it);
				--first_it;
				--second_it;
			}
		} 

		void ford_jhonson_sort(std::vector<int>& nums, int unit_size)
		{
			int possible_pairs = nums.size() / unit_size;
			bool odd_exists = false;
			if ( possible_pairs < 2)
				return ;
			if ( possible_pairs % 2 != 0)
			{
				possible_pairs--;
				odd_exists = true;
			}
			for ( int i = unit_size - 1, comp = 0; comp < possible_pairs / 2; comp++, i += unit_size * 2)
			{
				//compare the biggest number of each unit to the next one if they are unsorted switch the whole units
				if ( nums[i] > nums[i + unit_size])
					switch_units(nums, i, i + unit_size, unit_size);
			}
			// recurse over the vector with double the unit size
			ford_jhonson_sort(nums, unit_size * 2);

			std::vector<int> main;
			std::vector<int> pend;
			//serves as a simplified indexing of the biggest elements of each unit in order to do the binary search only on the biggest element of the chain
			std::vector<int> unit_leader;

			//insert the first and the second element of the vector since we know b1 is less then a1
			main.insert(main.begin(), nums.begin(), nums.begin() + (unit_size * 2));
			unit_leader.push_back(main[unit_size - 1]);
			unit_leader.push_back(main[((2 * unit_size) - 1)]);
			int pend_count = 0;
			vec_iterator b_element = nums.begin() + (unit_size * 2);
			vec_iterator a_element = b_element + unit_size;
			//insert all the big element of each pair of comparison in the main chain and the smallest of the pair into the pend chain the element can have a vairant size from 1 to ... they are not forcefully pairs
			for ( int i = 2; i < possible_pairs; i+= 2)
			{
				unit_leader.push_back(*(a_element + (unit_size -1)));
				pend.insert(pend.end(), b_element, b_element + unit_size);
				main.insert(main.end(), a_element, a_element + unit_size);
				a_element += unit_size * 2;
				b_element += unit_size * 2;
				pend_count++;
			}
			if ( odd_exists )
			{
				// add the odd element whih couldnt find another unit to compare itself with , the element is situated after the last a element 
				vec_iterator odd_start = nums.begin() + ( unit_size * possible_pairs); 
				pend.insert(pend.end(), odd_start, odd_start + unit_size);
				pend_count++;
			}
			
			// the pairs of pairs of pairs ..... sort is now done , and the construction of the main and pend chain is done 
			// we now need to insert the elements of the pend chain into the main chain using the jacob sthall sequence 
			/* which goes as follows:
				we iterate over the jacob sthall seuence first starting with 3 and then we substract it from the previous jacob sthal number 
				this gives us how many elements should be pushed from the pend to the main
				we start at the end of the result of the substraction meaning 3 -1 = 2 we start at the index 1 and work backwards insert 1 the insert 0
				if the result of the substraction is bigger then how many elements are in the pend chain we break out
				the insertion is done using binary search from the the begining of the nums up to the bound element 
				the bound element is the matching pair of the pend element tha is first pointed to by the jacob sthall meaning the first one to be inserted each time we recalculate the jacob sthall number
				if the pend element to be first inserted in the first iteration of the first insertion( jacob sthal 3) b3 then the bound is the matching one of that pair a3 
				and since we already know that the main chain has b1 a1 a2 a3 then the index of the match is 3 which is the same as the jacob sthall number ,
				this stays true for all elemnents if we ont push anything into the main chain , but since we are updating it with elements from the pend we have to adjust that wit ading to the bound 
				how many elements we inserted
				when inserting an element it could be supposed to be inserted above the bound by one meaning the bound willb now invalid so we need to move it back one place.
			*/

			size_t i = 0;
			size_t on_limit = 0;
			size_t current_jacob;
			size_t inserted_count = 0;
			size_t previous_jacob = 1;
			size_t number_of_insertions;


			while ( pend.size() )
			{
				current_jacob = jacob_sequence[i];
				number_of_insertions = current_jacob - previous_jacob;
				if ( number_of_insertions * unit_size > pend.size() )
					break;
				vec_iterator pend_leader = pend.begin() + (number_of_insertions * unit_size) - 1;
				
				vec_iterator erase_pend = pend_leader;
				while ( number_of_insertions )
				{
					vec_iterator search_limit = unit_leader.begin() + current_jacob + inserted_count - on_limit;
					// if ( search_limit > unit_leader.end())
					// {
					// 	// on_limit++;
					// 	std::cout << (pend_leader - pend.begin()) << "size " << pend.size() << std::endl;
					// 	std::cout << "unit size " << unit_size << " pend element " << *pend_leader << std::endl;
					// 	search_limit = unit_leader.end();
					// }
					vec_iterator leader_it = std::upper_bound( unit_leader.begin(), search_limit, *pend_leader);
					if ( search_limit == leader_it )
						on_limit++;
					size_t insert_at = leader_it - unit_leader.begin();
					unit_leader.insert(leader_it, *pend_leader);
					vec_iterator main_insert = main.begin() + (insert_at * unit_size);

					main.insert(main_insert, pend_leader - unit_size + 1, pend_leader + 1);
					pend_leader -= unit_size;
					number_of_insertions--;
					pend_count--;
					inserted_count++;
				}
				pend.erase(pend.begin(), erase_pend + 1);
				on_limit = 0;
				previous_jacob = current_jacob;
				i++;
			}

			// element might not all be inserted with the jacob sthall insertion style since the jacob number might be too big 
			// then we need to insert the remaining eements in reverese order
			// to calculate the search limit for the each of the ramaining elements we use 
			// size_of_main - size_of_pend + index_of_current_pend. */
			if ( pend.size() )
			{
				vec_iterator pend_leader = pend.end() - 1;

				pend_count = pend.size() / unit_size;
				for ( int i = pend.size() - 1; i >= 0; i-= unit_size)
				{
					vec_iterator search_limit = unit_leader.begin() + ( (unit_leader.size() - pend_count) + (i / unit_size) + odd_exists);
					if ( search_limit > unit_leader.end())
						search_limit = unit_leader.end();
					vec_iterator leader_it = std::upper_bound(unit_leader.begin(), search_limit, *pend_leader);
					int insert_at = leader_it - unit_leader.begin();

					unit_leader.insert(leader_it, *pend_leader);
					main.insert(main.begin() + (insert_at * unit_size), pend_leader - unit_size + 1, pend_leader + 1);
					pend_leader -= unit_size;
				}
			}
			for ( size_t i = 0; i < main.size(); i++)
			{
				nums[i] = main[i];
			}
		}
		
		std::vector<int> sort_numbers( std::vector<int> nums)
		{
			if ( is_sorted(nums))
				return nums;
			generate_jacob_sequence(nums.size());
			ford_jhonson_sort(nums, 1);
			return nums;
		}
};


#endif