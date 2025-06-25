#include "Intern.hpp"

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*forms_maker[3])(std::string) = {&Intern::makeRobot, &Intern::makePardon, &Intern::makeShrubbery};
	for ( int i = 0; i < 3; i++)
	{
		if ( name == forms[i] )
			return (this->*forms_maker[i])(target);
	}
	return NULL;
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobot(std::string target)
{
	return new RobotomyRequestForm(target);
}
