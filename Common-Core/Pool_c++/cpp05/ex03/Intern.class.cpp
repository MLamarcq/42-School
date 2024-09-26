#include "Intern.class.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}
Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}
Intern & Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern copy operator called" << std::endl;
	(void)rhs;
	return (*this);
}

void	Intern::check_before_form(std::string name) const
{
	if (name.compare("Presidential pardon form") != 0 && name.compare("Robotomy request form") != 0 && name.compare("Shrubbery creation form") != 0)
		throw (WrongNameException());
	return ;
}

AForm	*Intern::setPresidential(std::string target) const
{
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}

AForm	*Intern::setRobotomy(std::string target) const
{
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}

AForm	*Intern::setShrubbery(std::string target) const
{
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}

AForm	*Intern::chooseForm(std::string name, std::string target) const
{
	AForm *form = NULL;
	std::string str[3] = {"Presidential pardon form", "Robotomy request form", "Shrubbery creation form"};
	AForm	*(Intern::*choose[3]) (std::string target) const = {&Intern::setPresidential, &Intern::setRobotomy, &Intern::setShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(str[i]) == 0)
		{
			form = (this->*choose[i])(target);
			break ;
		}
	}
	return (form);
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	try
	{
		check_before_form(name);
	}
	catch (WrongNameException &e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
	return (chooseForm(name, target));
}

const char *Intern::WrongNameException::what() const throw()
{
	return ("Wrong form name. Intern can't create it");
}