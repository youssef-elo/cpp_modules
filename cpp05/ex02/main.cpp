#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	PresidentialPardonForm a("k");
	RobotomyRequestForm b("k");
	ShrubberyCreationForm c("k");

	Bureaucrat t("hh", 1);
	c.execute(t);
}