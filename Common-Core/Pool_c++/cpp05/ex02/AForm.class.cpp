#include "AForm.class.hpp"

AForm::AForm(void)
{
	std::cout << "AForm default constructor called" << std::endl;
	this->_name = "Default form";
	this->_exec_grade = 1;
	this->_signed = false;
	this->_sign_grade = 1;
	return ;
}
AForm::AForm(std::string name, int signGrade, int execGrade)
{
	std::cout << "AForm name assignement constructor called" << std::endl;
	this->_name = name;
	this->_signed = false;
	if ((this->_sign_grade = checkGrade(signGrade, 1)) == 0)
		return ;
	if ((this->_exec_grade = checkGrade(execGrade, 2)) == 0)
		return ;
	return ;
}

AForm::AForm(AForm const &src)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

AForm & AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_sign_grade = rhs.getSignGrade();
		this->_exec_grade = rhs.getExecGrade();

	}
	return (*this);
}

std::string 	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int		AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

int		AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	 AForm::checkGrade(int grade, int nb)
{
	try
	{
		if (grade < 1)
		{
			throw (GradeTooHighExecption());
		}
		if (grade > 150)
		{
			throw (GradeTooLowExecption());
		}
	}
	catch (GradeTooHighExecption &e)
	{
		std::cerr << e.what() << std::endl;
		bool toggle = false;
		std::string input;
		int temp = 0;
		while (toggle == false)
		{
			std::cout << "We must change that grade. Please, type a grade between 1 and 150 : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called. End of program" << std::endl;
				return (0);
			}
			if (is_digit(input) == 0)
				input.erase();
			else
			{
				temp = std::atoi(input.c_str());
				if (temp >= 1 || temp <= 150)
					toggle = true;
				else
					input.erase();
			}
		}
		if (nb == 1)
			return (this->_sign_grade = temp);
		else
			return (this->_exec_grade = temp);

	}
	catch (GradeTooLowExecption &e)
	{
		std::cerr << e.what() << std::endl;
		bool toggle = false;
		std::string input;
		int temp = 0;
		while (toggle == false)
		{
			std::cout << "We must change that grade. Please, type a grade between 1 and 150 : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called. End of program" << std::endl;
				return (0);
			}
			if (is_digit(input) == 0)
				input.erase();
			else
			{
				temp = std::atoi(input.c_str());
				if (temp >= 1 || temp <= 150)
					toggle = true;
				else
					input.erase();
			}
		}
		if (nb == 1)
			return (this->_sign_grade = temp);
		else
			return (this->_exec_grade = temp);
	}
	return (grade);
}

void	AForm::check_sign(Bureaucrat const &bureaucrat) const
{
	if (this->_signed == true)
	{
		throw (AlreadySignedException());
	}
	if (bureaucrat.getGrade() > this->_sign_grade)
	{
		throw (SignGradeTooLowExecption());
	}
	return ;
}

void	AForm::beSigned(Bureaucrat & bureaucrat)
{
	try
	{
		check_sign(bureaucrat);
	}
	catch (AlreadySignedException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		return ;
	}
	catch (SignGradeTooLowExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		return ;
	}
	this->_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	return ;
}


int			AForm::is_letter(std::string str) const
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

int			AForm::is_digit(std::string str) const
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	AForm::check_execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_exec_grade)
	{
		throw (ExecuteTooLowException());
	}
	if (this->_signed == false)
	{
		throw (NotSignedException());
	}
	return ;
}


const char *AForm::GradeTooLowExecption::what() const throw()
{
	return ("Bureaucrat's sign or exec grade too low. It must be lower or equal to 150");
}
const char *AForm::GradeTooHighExecption::what() const throw()
{
	return ("Bureaucrat's sign or exec grade too high. It must be higher or equal to 1");
}
const char *AForm::SignGradeTooLowExecption::what() const throw()
{
	return ("Bureaucrat's sign grade is too low to sign form");
}
const char *AForm::ExecuteTooLowException::what() const throw()
{
	return ("Grade too low to execute form");
}
const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not sign");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already sign. Can't sign anymore");
}

std::ostream &operator<<(std::ostream &ost, AForm const &rhs)
{
	ost << "Form name : " << rhs.getName() << std::endl;
	ost << "Sign's grade : " << rhs.getSignGrade() << std::endl;
	ost << "Exec's grade : " << rhs.getExecGrade() << std::endl;
	if (rhs.getSigned() == false)
		ost << rhs.getName() << " is unsgined" << std::endl;
	else
		ost << rhs.getName() << " is signed" << std::endl;
	return (ost);
}