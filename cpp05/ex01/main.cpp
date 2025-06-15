#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat bureaucrat1("simo", 1);
	Form form1("chahadat l7ayat", 8, 10);

	std::cout << form1 << std::endl;
	bureaucrat1.signForm(form1);
	std::cout << form1 << std::endl;

}
