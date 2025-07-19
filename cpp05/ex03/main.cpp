#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern modernslave;
	Bureaucrat t("top-bureaucrat", 1);
	AForm *a = modernslave.makeForm("presidential pardon", "most wanted");
	AForm *b = modernslave.makeForm("robotomy request", "C80-47");
	AForm *c = modernslave.makeForm("shrubbery creation", "tree");

	if ( !a || !b || !c)
	{
		delete a; 
		delete b;
		delete c;
		return 1;
	}

	t.executeForm(*a);
	t.executeForm(*b);
	t.executeForm(*c);
	std::cout << std::endl << std::endl;
	
	t.signForm(*a);
	t.signForm(*b);
	t.signForm(*c);
	std::cout << std::endl << std::endl;
	
	t.executeForm(*a);
	std::cout << std::endl;
	t.executeForm(*b);
	std::cout << std::endl;
	t.executeForm(*c);

	std::cout << std::endl << std::endl;
	delete a;
	delete b;
	delete c;
}
