#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target_arg):
	AForm("PresidentialPardonForm", 145, 137),
	target(target_arg){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
	AForm(other),
	target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if ( this == &other)
		return *this;
	target = other.target;
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << getName() << " form is being destructed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getFormState() == false)
		throw std::runtime_error("Form is not signed failed to execute.");
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;	
}
