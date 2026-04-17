#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() :
			AForm("ShrubberyCreationForm default", 145, 137),
			_target("Default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
			AForm("ShrubberyCreationForm", 145, 137),
			_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
			AForm(other),
			_target(other._target)
{}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "      oxoxoo    ooxoo" << std::endl;
		file << "    ooxoxo oo  oxoxooo" << std::endl;
		file << "   ooo ooxooo  ooo oxox" << std::endl;
		file << "    oxoo oo oxoo  ooo ooo" << std::endl;
		file << "      |o o|  |o o|" << std::endl;
		file << "      |   |  |   |" << std::endl;
		file.close();
		std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
	}
}
