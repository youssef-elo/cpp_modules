#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iostream>



class Span
{
	private:
		typedef std::multiset<int>::iterator iterator;
		Span();
		std::multiset<int> container;
		unsigned int span_size;
	public:
		~Span();
		Span( unsigned int size );
		Span( const Span& other );
		Span& operator=( const Span& other );

		int longestSpan();
		int shortestSpan();
		void addNumber(int nb);
		template < typename Iterator >
		void insert(Iterator start, Iterator end);
		
};

template < typename Iterator >
void Span::insert(Iterator start, Iterator end)
{
	unsigned int remaining = span_size - container.size();
	if ( end - start <= remaining )
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

#endif