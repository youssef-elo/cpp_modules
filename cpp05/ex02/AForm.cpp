#include "AForm.hpp"


const std::string& AForm::getName() const
{
	return name_;
}

int AForm::getSigngrade() const
{
	return sign_grade_;
}

int AForm::getExecuteGrade() const
{
	return execute_grade_;
}

bool AForm::getFormState() const
{
	return sign_;
}

void AForm::beSigned(const Bureaucrat& signer)
{
	if ( signer.getGrade() > sign_grade_)
		throw AForm::GradeTooLowException();
	else
		sign_ = true;
}

AForm::~AForm()
{
	std::cout << "AForm: " << name_ << " is being destructed" << std::endl;
}

AForm::AForm(const AForm &other): name_(other.name_) , sign_grade_(other.sign_grade_), execute_grade_(other.execute_grade_), sign_(other.sign_){}

AForm &AForm::operator=(const AForm &other)
{
	if ( this == &other)
		return *this;
	sign_ = other.sign_;
	return *this;
}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade) : name_(name), sign_grade_(sign_grade), execute_grade_(execute_grade), sign_(false){}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
	out << "AForm name: " << other.getName() << std::endl
		<< "Required sign grade: " << other.getSigngrade() << std::endl
		<< "Required execution grade: " << other.getExecuteGrade() << std::endl
		<< "AForm state : " << (other.getFormState()? "signed": "unsigned") << std::endl;
	return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade error: Grade too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade error: Grade too low";
}
