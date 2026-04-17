#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== TEST 1: The High Council =====" << std::endl;
	try {
		Bureaucrat president("Zaphod", 1);
		ShrubberyCreationForm f1("Garden");
		RobotomyRequestForm f2("Bender");
		PresidentialPardonForm f3("Arthur Dent");

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		president.signForm(f1);
		president.signForm(f2);
		president.signForm(f3);

		president.executeForm(f1);
		president.executeForm(f2);
		president.executeForm(f3);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 2: The Intern Struggle =====" << std::endl;
	try {
		Bureaucrat intern("Poor Guy", 150);
		RobotomyRequestForm f2("Wall-E");

		intern.signForm(f2);
		intern.executeForm(f2);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 3: Signed but weak Bureaucrat =====" << std::endl;
	try {
		Bureaucrat middleMan("Middle", 70);
		RobotomyRequestForm f2("R2D2");

		middleMan.signForm(f2);
		middleMan.executeForm(f2);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== TEST 4: Execution without Sign =====" << std::endl;
	try {
		Bureaucrat boss("Boss", 5);
		PresidentialPardonForm f3("Marvin");

		boss.executeForm(f3);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
