#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		void execute(Bureaucrat const &executor) const;

		~RobotomyRequestForm();
		RobotomyRequestForm( std::string target_arg);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=( const RobotomyRequestForm& other);
};

#endif