#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		AForm *makeShrubbery( std::string target );
		AForm *makePardon( std::string target );
		AForm *makeRobot( std::string target );
	public:
		AForm *makeForm( std::string name, std::string target );
	
};

#endif