#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm( std::string target_arg);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=( const PresidentialPardonForm& other);

		void execute(Bureaucrat const &executor) const;
};


#endif