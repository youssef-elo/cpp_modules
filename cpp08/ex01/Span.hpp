#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iostream>
#include <iterator>

class Span
{
	private:
		Span();
		unsigned int span_size;
		std::multiset<int> container;
		typedef std::multiset<int>::iterator iterator;
	public:
		~Span();
		Span( unsigned int size );
		Span( const Span& other );
		Span& operator=( const Span& other );

		unsigned long longestSpan();
		unsigned long shortestSpan();
		void addNumber(int nb);
		template < typename It >
		void insert(It start, It end)
		{
			long long insert_size = std::distance(start, end);
			if ( insert_size < 0)
				throw std::runtime_error("Cannot calculate the distance between the iterators.");
			long long remaining = span_size - container.size();
			if ( insert_size <= remaining )
			{
				container.insert(start, end);
				return ;
			}
			else
			{
				container.insert(start , start + remaining);
				throw std::runtime_error("Span is full cannot insert more elements.");
			}
		}
};

#endif