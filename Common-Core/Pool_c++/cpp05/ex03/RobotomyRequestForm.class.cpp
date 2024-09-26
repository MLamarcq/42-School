#include "RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->_target = "No target";
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm target assignement constructor called" << std::endl;
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

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm desctructor called" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

int		RobotomyRequestForm::is_letter(std::string str) const
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

void	RobotomyRequestForm::execute(Bureaucrat const&bureaucrat)
{
	try
	{
		check_execute(bureaucrat);
	}
	catch (ExecuteTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't execute RobotomyRequestForm due to his low grade (" << bureaucrat.getGrade() << ")" << std::endl;
		return ; 
	}
	catch (NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't execute RobotomyRequestForm because it is not sign." << std::endl;
		return ;
	}
	unsigned int nb = std::rand();
	if ((nb % 2) == 0)
	{
		std::cout << "Bzzzzzz Bzzzzz (this is a drill sound). " << this->_target << " has been robotized !" << std::endl;
	}
	else
		std::cout << "Operation have failed" << std::endl;
	return ;
}
