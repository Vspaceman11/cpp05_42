#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other) {*this = other;}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(){}


AForm* Intern::createShrubbery(const std::string& target) const { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(const std::string& target) const { return new RobotomyRequestForm(target); }
AForm* Intern::createPardon(const std::string& target) const { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string forms[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[] =
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(formTarget);
		}
	}
	std::cout << "Error: Intern cannot create form '" << formName << "' (unknown name)." << std::endl;
	return nullptr;
}
