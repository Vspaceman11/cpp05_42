#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() :
			AForm("RobotomyRequestForm default", 72, 45),
			_target("Default target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
			AForm("RobotomyRequestForm", 72, 45),
			_target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
			AForm(other),
			_target(other._target)
{}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "* VRRRRRRRRRR * (drilling noises)" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed." << std::endl;

}
