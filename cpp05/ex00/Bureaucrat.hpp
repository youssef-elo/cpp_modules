#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		Bureaucrat(const std::string& name_arg, int grade_arg);

		int getGrade() const;
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		const std::string &getName() const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif