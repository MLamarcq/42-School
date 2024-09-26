#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	this->_name = "Boss";
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
	std::cout << "Bureaucrat name and grade assignement constructor called" << std::endl;
	this->_name = name;
	if (is_letter(this->_name) == 0)
	{
		this->_name.erase();
		bool toggle = false;
		std::string input;
		while (toggle == false)
		{
			std::cout << "Wrong name set. Please choose another one : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called. End of program" << std::endl;
				return ;
			}
			if (is_letter(input) == 0)
				input.erase();
			else
			{
				this->_name = input;
				toggle = true;
				std::cout << std::endl;
			}
		}
	}
	std::string string_grade = intTostring(grade);
	if (is_digit(string_grade) == 0)
	{	
		bool toggle = false;
		std::string input;
		int			grade_2 = 0;
		while (toggle == false)
		{
			std::cout << "Wrong grade set. Please choose another one : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called. End of program" << std::endl;
				return ;
			}
			if (is_digit(input) == 0)
				input.erase();
			else
			{
				grade_2 = std::atoi(input.c_str());
				this->_grade = checkGrade(grade_2);
				toggle = true;
			}
		}
	}
	else
		this->_grade = checkGrade(grade);
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

int			Bureaucrat::is_letter(std::string str)
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

int			Bureaucrat::is_digit(std::string str)
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

void		Bureaucrat::IncreaseGrade(void)
{
	int grade = this->_grade;
	grade--;
	std::cout << "Bureaucrate " << this->_name << " is getting a upper grade" << std::endl;
	this->_grade = checkGrade(grade);
	return ;
}
void		Bureaucrat::DecreaseGrade(void)
{
	int grade = this->_grade;
	grade++;
	std::cout << "Bureaucrat " << this->_name << " is getting a lower grade" << std::endl;
	this->_grade = checkGrade(grade);
	return ;
}

int			Bureaucrat::checkGrade(int grade) const
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
		std::cerr << "Bureaucrat " << this->_name << " grade's is 150" << std::endl << std::endl;
		return (150);
	}
	catch (GradeTooHighExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Bureaucrat " << this->_name << " grade's is 1" << std::endl << std::endl;
		return (1);
	}
	return (grade);
}

std::string Bureaucrat::intTostring(int number)
{
	std::string result;
	char digitChar;
	
	while (number <= 0)
	{
		std::srand(0);
		number = std::rand();
	}
	while (number > 0) 
	{
		digitChar = '0' + (number % 10);
		result.push_back(digitChar);
		number /= 10;
	}
	if (result.size() > 4)
		result = result.substr(0, 4);
	return (result);
}

void	Bureaucrat::signForm(AForm const &Aform)
{
	try
	{
		if (this->_grade > Aform.getSignGrade())
		{
			throw(SignedFormExecption());
		}
		if (Aform.getSigned() == false)
		{
			throw(NotSignedExecption());
		}
	}
	catch (SignedFormExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << " couldn't sign " << Aform.getName() << " because " << this->_name << "'s grade is too low." << std::endl;
		return ;
	}
	catch (NotSignedExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << " couldn't sign " << Aform.getName() << " because " << Aform.getName() << " is not signed." << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << Aform.getName() << std::endl;
	return ;
}

void	Bureaucrat::checkForm(AForm const &form) const
{
	if (form.getSigned() == false)
	{
		throw (NotSignedExecption());
	}
	if (form.getExecGrade() < this->_grade)
	{
		throw (GradeLowExecExecption());
	}
	return ;
}


void	Bureaucrat::executeForm(AForm &form)
{
	try
	{
		checkForm(form);
	}
	catch (NotSignedExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << " can't execute " << form.getName() << " form because it is not sign" << std::endl;
		return ;
	}
	catch (GradeLowExecExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << " can't execute " << form.getName() << " form. His grade is too low" << std::endl;
		return ;
	}
	form.execute(*this);
	std::cout << this->_name << " is executing " << form.getName() << std::endl;
	return ;
}



const char *Bureaucrat::GradeTooHighExecption::what() const throw()
{
	return ("Bureaucrat is already at the top of the company. How can he be higher ?\n");
}

const char *Bureaucrat::GradeTooLowExecption::what() const throw()
{
	return ("Bureaucrat is already at the bottom of the company. How can he be lower ?\n");
}

const char *Bureaucrat::GradeLowExecExecption::what() const throw()
{
	return ("Bureaucrat's grade too low to execute form\n");
}

const char* Bureaucrat::NotSignedExecption::what() const throw()
{
	return ("Form is not signed\n");
}

const char *Bureaucrat::SignedFormExecption::what() const throw()
{
	return ("Bureaucrat's grade is too low to sign form\n");
}


std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs)
{
	ost << rhs.getName() << " bureaucrat grade " << rhs.getGrade() << std::endl;
	return (ost);
}