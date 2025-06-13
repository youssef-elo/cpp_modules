#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat *subject;

	try{
		subject = new Bureaucrat("simo", 3);
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
		int a = 0;
		if (a)
			a=0;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}`
	std::cout << (*subject) << std::endl;
	delete subject;
}