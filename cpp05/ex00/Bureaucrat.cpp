#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name_arg, int grade_arg) : name(name_arg) , grade(grade_arg)
{
	if ( grade < 1)
		Bureaucrat::GradeTooHighException("Grade is out of upper range.");
	if ( grade > 150)
		Bureaucrat::GradeTooLowException("Grade is out of lower range.");
}


Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) , grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	if ( this == &other)
		return *this;
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name << "is being destructed" <<  std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

Bureaucrat& Bureaucrat::operator--(int)
{
	if (grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException("Grade is out of lower range.");
	}
	grade++;
}
Bureaucrat& Bureaucrat::operator++(int)
{
	if (grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException("Grade is out of upper range.");
	}
	grade--;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string error_arg) : error_message(error_arg){}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string error_arg) : error_message(error_arg){}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return error_message.c_str();
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return error_message.c_str();
}
