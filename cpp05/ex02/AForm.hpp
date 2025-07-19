#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		const int sign_grade_;
		const int execute_grade_;
		bool sign_;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		AForm(const std::string& name, int sign_grade, int execute_grade);

		virtual void execute(Bureaucrat const& executor) const = 0;

		int getSigngrade() const;
		bool getFormState() const;
		int getExecuteGrade() const;
		const std::string& getName() const;

		void beSigned(const Bureaucrat& signer);

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

std::ostream& operator<<(std::ostream& out, const AForm& other);

#endif