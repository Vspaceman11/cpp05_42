#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern  someRandomIntern;
	Bureaucrat boss("Boss", 1);
	AForm* rrf;

	std::cout << "--- Test 1: Successful Robotomy Creation ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- Test 2: Successful Shrubbery Creation ---" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- Test 3: Successful Pardon Creation ---" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n--- Test 4: Unknown Form Name ---" << std::endl;
	rrf = someRandomIntern.makeForm("coffee request", "Boss");
	if (!rrf)
	{
		std::cout << "Intern failed as expected, no memory allocated." << std::endl;
	}

	return 0;
}
