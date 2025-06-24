#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	PresidentialPardonForm a("Criminal");
	RobotomyRequestForm b("83-Dc");
	ShrubberyCreationForm c("tree");
	Bureaucrat t("top-bureaucrat", 5);

	t.executeForm(a);
	t.executeForm(b);
	t.executeForm(c);
	std::cout << std::endl << std::endl;
	
	t.signForm(a);
	t.signForm(b);
	t.signForm(c);
	std::cout << std::endl << std::endl;
	
	t.executeForm(a);
	std::cout << std::endl;
	t.executeForm(b);
	std::cout << std::endl;
	t.executeForm(c);

	std::cout << std::endl << std::endl;
}