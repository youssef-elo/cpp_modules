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
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;


	std::cout << "Testing large number of elements :" << std::endl;
	Span big_span(10000);
	for (int i = 0; i < 10000; i++)
		big_span.addNumber(i);
	std::cout << "longest span : " << big_span.longestSpan() << std::endl
			  << "shortest span : " << big_span.shortestSpan() << std::endl;

	std::vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); i++)
		vec[i] = i;

	Span spa(10);
	std::cout << std::endl;
	try
	{

		spa.insert(vec.begin(), vec.end());
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
		return 0;
	}
	std::cout << "Testing range iterators insert :" << std::endl;
	std::cout << "Shortest span : " << spa.shortestSpan() << std::endl;
	std::cout << "Longest span : " << spa.longestSpan() << std::endl;
	std::cout << std::endl;

	return 0;
}