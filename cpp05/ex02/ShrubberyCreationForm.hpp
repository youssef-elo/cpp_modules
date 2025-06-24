#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		void execute(Bureaucrat const & executor) const;

		~ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target_arg);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other);
};


#endif