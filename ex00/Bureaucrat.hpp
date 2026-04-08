#pragma once
#include <string>
#include <iostream>
class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};

	private:
		const std::string	_name;
		int					_grade;
};
