#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(0);
	sp.addNumber(1);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	Span big_span(10000);
	for ( int  i = 0 ; i < 10000; i++)
		big_span.addNumber(i);
	std::cout << "longest span : "<< big_span.longestSpan() << std::endl << "shortest span : " << big_span.shortestSpan() << std::endl;
	return 0;
}