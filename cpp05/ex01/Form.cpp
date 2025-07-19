#include "Form.hpp"

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

void Form::beSigned(const Bureaucrat& signer)
{
	if ( signer.getGrade() > sign_grade_)
		throw Form::GradeTooLowException();
	else
		sign_ = true;
}


Form &Form::operator=(const Form &other)
{
	if ( this == &other)
		return *this;
	sign_ = other.sign_;
	return *this;
}

Form::~Form()
{
	std::cout << "Form: " << name_ << " is being destructed" << std::endl;
}

Form::Form() : name_("Default Form"), 
			sign_grade_(150), 
			execute_grade_(150), 
			sign_(false) {}

Form::Form(const Form &other): name_(other.name_) , sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_), sign_(other.sign_){}

Form::Form(const std::string &name, int sign_grade, int execute_grade) : 
			name_(name), 
			sign_grade_(sign_grade), 
			execute_grade_(execute_grade), 
			sign_(false)
{
	if ( sign_grade_ < 1 || execute_grade_ < 1)
		throw Form::GradeTooHighException();
	if ( sign_grade_ > 150 || execute_grade_ > 150)
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out << "Form name: " << other.getName() << std::endl
		<< "Required sign grade: " << other.getSigngrade() << std::endl
		<< "Required execution grade: " << other.getExecuteGrade() << std::endl
		<< "Form state : " << (other.getFormState()? "signed": "unsigned") << std::endl;
	return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade error: Grade too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade error: Grade too low";
}
