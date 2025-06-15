#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;
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
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		void signForm( Form& form);
		const std::string &getName() const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif