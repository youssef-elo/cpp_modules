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
	std::cout << "Requested Form doesn't exist" << std::endl;
	return NULL;
}

AForm *Intern::makeShrubbery(std::string target)
{
	AForm *ret;

	try
	{
		ret = new ShrubberyCreationForm(target);
	}
	catch (std::exception& ex)
	{
		std::cout << "intern failed to make from because " << ex.what() << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " <<  ret->getName() << std::endl;
	return ret;
}

AForm *Intern::makePardon(std::string target)
{
	AForm *ret;

	try
	{
		ret = new PresidentialPardonForm(target);
	}
	catch (std::exception& ex)
	{
		std::cout << "intern failed to make from because " << ex.what() << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return ret;
}

AForm *Intern::makeRobot(std::string target)
{
	AForm *ret;

	try
	{
		ret = new RobotomyRequestForm(target);
	}
	catch (std::exception& ex)
	{
		std::cout << "intern failed to make from because " << ex.what() << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return ret;
}

Intern::Intern()
{
	std::cout << "intern is being created" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern is being destructed" << std::endl;
}
Intern::Intern(const Intern& other)
{
	std::cout << "Intern is being created" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if ( this == &other )
		return *this; 
	return *this;
}
