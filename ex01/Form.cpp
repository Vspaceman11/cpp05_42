#include "Form.hpp"

Form::Form() :
			_name("Default Form"),
			_isSigned(false),
			_gradeToSign(150),
			_gradeToExecute(150)
{
	std::cout << "Default Constructor Form " << _name << " called" << std::endl;
}
Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
			_name(name),
			_isSigned(false),
			_gradeToSign(gradeToSign),
			_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	else if (gradeToExecute > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Parametrized Constructor Form " << _name << " called" << std::endl;
}

Form::Form(const Form& other) :
			_name(other._name),
			_isSigned(other._isSigned),
			_gradeToSign(other._gradeToSign),
			_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy Constructor Form " << _name << " called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << "Assign operator Form " << _name << " called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor Form called" << std::endl;
}

const std::string	Form::getName() const {return _name;}
const int			Form::getGradeToSign() const {return _gradeToSign;}
const int			Form::getGradeToExecute() const {return _gradeToExecute;}

void				Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high! Max value is 1!";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low! Minimum value is 150";
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
	os << Form.getName() << ", signed status" << Form.getIsSigned() << ", grade to sign " << Form.getGradeToSign()
		<< ", grade to execute " << Form.getGradeToExecute() << ".";
	return os;
}
