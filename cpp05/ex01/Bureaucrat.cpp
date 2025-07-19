#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name_arg, int grade_arg) : name(name_arg) , grade(grade_arg)
{
	if ( grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
	std::cout << name << " is being destructed" <<  std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

Bureaucrat& Bureaucrat::operator--()
{
	if (grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade++;
	return *this;
}

Bureaucrat& Bureaucrat::operator++()
{
	if (grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	grade--;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade error: Grade too High";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade error: Grade too Low";
}

void Bureaucrat::signForm( Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& ex)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << ex.what() << std::endl;
		return ;
	}
	std::cout << name << " signed " << form.getName() << std::endl;
}
