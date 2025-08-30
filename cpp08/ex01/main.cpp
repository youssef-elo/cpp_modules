#include "Span.hpp"
#include <vector>

int main()
{
	std::cout << "Subect's test :" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "\tShortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "\tLongest span : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing large number of elements :" << std::endl;
	Span big_span(10000);
	for (int i = 0; i < 10000; i++)
		big_span.addNumber(i);
	std::cout << "\tlongest span : " << big_span.longestSpan() << std::endl
			  << "\tshortest span : " << big_span.shortestSpan() << std::endl;

	int inititalizer[] = {0, 1, 2, 3, -4,5, 6, 7,8, 900, 10};
	std::vector<int> vec(inititalizer, inititalizer + (sizeof(inititalizer) / sizeof(inititalizer[0])));

	Span spa(10);
	std::cout << std::endl;
	try
	{
		spa.insert(vec.begin(), vec.end());
		// spa.insert(inititalizer, inititalizer + (sizeof(inititalizer) / sizeof(inititalizer[0])));
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "Testing range iterators insert :" << std::endl;
	std::cout << "\tShortest span : " << spa.shortestSpan() << std::endl;
	std::cout << "\tLongest span : " << spa.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "Empty Span object test: ";
	Span empty(0);
	try
	{
		empty.addNumber(84);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		empty.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
