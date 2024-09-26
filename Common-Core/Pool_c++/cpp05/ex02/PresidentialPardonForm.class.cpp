#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->_target = "No target";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm target assignement constructor called" << std::endl;
	if (is_letter(target) == 0 || target.empty())
	{
		std::string input;
		while (is_letter(input) == 0)
		{
			std::cout << "Wrong target format. Only letters accepted. Please try again : ";
			if (!(std::getline(std::cin, input)) == 0)
			{
				std::cout << "EOF called. End of program" << std::endl;
				return ;
			}
		}
		this->_target = input;
	}
	else
		this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm desctructor called" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

int		PresidentialPardonForm::is_letter(std::string str) const
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat)
{
	try
	{
		check_execute(bureaucrat);
	}
	catch (ExecuteTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can' t execute PresidentialPardonForm due to his low grade (" << bureaucrat.getGrade() << ")" << std::endl;
		return ; 
	}
	catch (NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't execute PresidentialPardonForm because it is not sign." << std::endl;
		return ;
	}
	std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
	return ;
}