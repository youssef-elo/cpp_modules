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

};



#endif