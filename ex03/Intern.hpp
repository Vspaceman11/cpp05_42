#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& formTarget);

	private:
		AForm* createShrubbery(const std::string& target) const;
		AForm* createRobotomy(const std::string& target) const;
		AForm* createPardon(const std::string& target) const;

		typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
};
