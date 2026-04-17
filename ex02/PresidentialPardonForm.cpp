#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() :
			AForm("PresidentialPardonForm default", 25, 5),
			_target("Default target")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string& target) :
			AForm("PresidentialPardonForm", 25, 5),
			_target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
			AForm(other),
			_target(other._target)
{}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException(); // Create exeption isFormSigned
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
