#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat *subject;

	try
	{
		subject = new Bureaucrat("bureaucrat", 149);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::cout << (*subject) << std::endl;
	try
	{
		--(*subject);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		delete subject;
		return 2;
	}
	std::cout << (*subject) << std::endl;
	delete subject;
}
