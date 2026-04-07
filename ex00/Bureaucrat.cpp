#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
			_name("Default Bureaucrat"),
			_grade(1)
{
	std::cout << "Default Constructor Bureaucrat " << _name << " called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade) :
			_name(name),
			_grade(grade)
{
	std::cout << "Parametrized Constructor Bureaucrat " << _name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
			_name(other._name),
			_grade(other._grade)
{
	std::cout << "Copy Constructor Bureaucrat " << _name << " called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	std::cout << "Assign operator Bureaucrat " << _name << " called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

std::string	Bureaucrat::getName() const {return _name;}
int			Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::incrementGrade()
{
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	_grade++;
}
