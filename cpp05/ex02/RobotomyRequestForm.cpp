#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
	AForm("RobotomyRequestForm", 72, 45),
	target("Default target") {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static unsigned int success;

	if (getFormState() == false)
		throw std::runtime_error("Form is not signed failed to execute.");
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	std::cout << "**Drilling Sounds**" << std::endl << target << ((success % 2 == 0) ? " has been robotomized successfully." : " robotomization failed try again later.") << std::endl;
	success++;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << getName() << " is being destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_arg) :
	AForm("RobotomyRequestForm", 72, 45),
	target(target_arg) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
	AForm(other),
	target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if ( this == &other)
		return *this;
	target = other.target;
	AForm::operator=(other);
	return *this;
}
