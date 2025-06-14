#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
	private:
		bool sign_;
		const int sign_grade_;
		const int execute_grade_;
		const std::string name_;

	public:
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		Form(const std::string& name, int sign_grade, int execute_grade);

		const std::string& getName() const;
		int getSigngrade() const;
		int getExecuteGrade() const;
		bool getFormState() const;

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

const std::string& Form::getName() const
{
	return name_;
}

int Form::getSigngrade() const
{
	return sign_grade_;
}

int Form::getExecuteGrade() const
{
	return execute_grade_;
}

bool Form::getFormState() const
{
	return sign_;
}

void Form::beSigned(const Bureaucrat &signer)
{
	
}

Form::~Form()
{
	std::cout << "Form: " << name_ << "is being destructed" << std::endl;
}

Form::Form(const Form &other): name_(other.name_) , sign_grade_(other.sign_grade_), sign_(other.sign_), execute_grade_(other.execute_grade_){}

Form &Form::operator=(const Form &other)
{
	if ( this == &other)
		return *this;
	sign_ = other.sign_;
	return *this;
}

Form::Form(const std::string &name, int sign_grade, int execute_grade) : sign_(false), name_(name), sign_grade_(sign_grade), execute_grade_(execute_grade) {}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out << "Form name: " << other.getName() << std::endl
		<< "Required sign grade: " << other.getSigngrade() << std::endl
		<< "Required execution grade: " << other.getExecuteGrade() << std::endl
		<< "Form state : " << (other.getFormState()? "signed": "unsigned") << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade error: Grade too high";
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade error: Grade too low";
}

#endif