#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
			_name("Default AForm"),
			_isSigned(false),
			_gradeToSign(150),
			_gradeToExecute(150)
{
	std::cout << "Default Constructor AForm " << _name << " called" << std::endl;
}
AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
			_name(name),
			_isSigned(false),
			_gradeToSign(gradeToSign),
			_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Parametrized Constructor AForm " << _name << " called" << std::endl;
}

AForm::AForm(const AForm& other) :
			_name(other._name),
			_isSigned(other._isSigned),
			_gradeToSign(other._gradeToSign),
			_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor AForm " << _name << " called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << "Assign operator AForm " << _name << " called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Destructor AForm called" << std::endl;
}

const std::string	AForm::getName() const {return _name;}
int					AForm::getGradeToSign() const {return _gradeToSign;}
int					AForm::getGradeToExecute() const {return _gradeToExecute;}
bool				AForm::getIsSigned() const {return _isSigned;}

void				AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high! Max value is 1!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low! Minimum value is 150";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form cannot be executed because it is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", signed status" << form.getIsSigned()
		<< ", grade to sign " << form.getGradeToSign()
		<< ", grade to execute " << form.getGradeToExecute() << ".";
	return os;
}
