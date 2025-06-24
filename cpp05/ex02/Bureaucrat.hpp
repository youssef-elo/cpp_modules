#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		Bureaucrat(const std::string& name_arg, int grade_arg);

		int getGrade() const;
		void executeForm(AForm const &form);
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		void signForm( AForm& form);
		const std::string &getName() const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif