#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		const int sign_grade_;
		const int execute_grade_;
		bool sign_;

	public:
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		Form(const std::string& name, int sign_grade, int execute_grade);

		const std::string& getName() const;
		int getSigngrade() const;
		int getExecuteGrade() const;
		bool getFormState() const;

		void beSigned(const  Bureaucrat& signer);

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
};

std::ostream& operator<<(std::ostream& out, const Form& other);

#endif