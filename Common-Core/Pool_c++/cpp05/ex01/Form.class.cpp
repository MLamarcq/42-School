#include "Form.class.hpp"

Form::Form(void)
{
	std::cout << "Form default constructor called" << std::endl;
	this->_name = "Boss's form";
	this->_signed = false;
	this->_sign_grade = 1;
	this->_exec_grade = 1;
	return ;
}
Form::Form(std::string name, int sign_grade, int exec_grade)
{
	std::cout << "Form assignement constructor called" << std::endl;
	
	this->_name = name;
	this->_sign_grade = checkGrade(sign_grade);
	if (this->_sign_grade == 0)
		return ;
	this->_exec_grade = checkGrade(exec_grade);
	if (this->_exec_grade == 0)
		return ;
	this->_signed = false;
	return ;
}

Form::Form(Form const &src)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form & Form::operator=(Form const &rhs)
{
	std::cout << "Form copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_sign_grade = checkGrade(rhs.getSignGrade());
		this->_exec_grade = checkGrade(rhs.getExecGrade());
	}
	return (*this);
}

std::string 	Form::getName(void) const
{
	return (this->_name);
}

bool			Form::getSigned(void) const
{
	return (this->_signed);
}

int				Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

int				Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

const char * Form::GradeTooLowExecption::what() const throw()
{
	return ("Grade too low. Can't be more than 150 !\n");
}

const char * Form::GradeTooHighExecption::what() const throw()
{
	return ("Grade too high. Can't be less than 1 !\n");
}

const char *Form::SignedGradeBadException::what() const throw()
{
	return ("Bureaucrate can't sign, grade too low\n");
}

const char * Form::SignedFormBadException::what() const throw()
{
	return ("Form is already signed. Can't sign again\n");
}

void		Form::beSigned(Bureaucrate &bureaucrate)
{
	try
	{
		if (bureaucrate.getGrade() > this->_sign_grade)
		{
			throw(SignedGradeBadException());
		}
		if (this->_signed == true)
		{
			throw(SignedFormBadException());
		}
	}
	catch (SignedGradeBadException &e)
	{
		std::cerr << bureaucrate.getName() <<  " has a grade (" << bureaucrate.getGrade() << ") lower than sign grade (" << this->_sign_grade << ")." << std::endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
	catch (SignedFormBadException &e)
	{
		std::cerr << bureaucrate.getName() << " can't sign." << std::endl;
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << bureaucrate.getName() << " has signed " << this->_name << std::endl << std::endl;
	this->_signed = true;
	return ;
}


int			Form::checkGrade(int grade) const
{
	try
	{
		if (grade > 150)
		{
			throw (GradeTooLowExecption());
		}
		if (grade < 1)
		{
			throw(GradeTooHighExecption());
		}
	}
	catch (GradeTooLowExecption &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	catch (GradeTooHighExecption &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (grade);
}


int			Form::is_letter(std::string str) const
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

int			Form::is_digit(std::string str) const
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


std::ostream & operator<<(std::ostream &ost, Form const &rhs)
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