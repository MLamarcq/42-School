#include "Bureaucrat.class.hpp"

Bureaucrate::Bureaucrate(void)
{
	std::cout << "Bureaucrate default constructor called" << std::endl;
	this->_name = "Boss";
	this->_grade = 1;
	return ;
}
Bureaucrate::Bureaucrate(std::string const name, int grade)
{
	std::cout << "Bureaucrate name and grade assignement constructor called" << std::endl;
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

Bureaucrate::Bureaucrate(Bureaucrate const &src)
{
	std::cout << "Bureaucrate copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrate::~Bureaucrate(void)
{
	std::cout << "Bureaucrate destructor called" << std::endl;
	return ;
}

Bureaucrate & Bureaucrate::operator=(Bureaucrate const &rhs)
{
	std::cout << "Bureaucrate copy operator called" << std::endl << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = checkGrade(rhs.getGrade());
	}
	return (*this);
}

std::string Bureaucrate::getName(void) const
{
	return (this->_name);
}

int			Bureaucrate::getGrade(void) const
{
	return (this->_grade);
}

int			Bureaucrate::is_letter(std::string str)
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

int			Bureaucrate::is_digit(std::string str)
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

void		Bureaucrate::IncreaseGrade(void)
{
	int grade = this->_grade;
	grade--;
	this->_grade = checkGrade(grade);
	if (this->_grade == 1 || this->_grade == 150)
		return ;
	std::cout << "Bureaucrate " << this->_name << " is getting a upper grade" << std::endl;
	return ;
}
void		Bureaucrate::DecreaseGrade(void)
{
	int grade = this->_grade;
	grade++;
	this->_grade = checkGrade(grade);
	if (this->_grade == 1 || this->_grade == 150)
		return ;
	std::cout << "Bureaucrate " << this->_name << " is getting a lower grade" << std::endl;
	return ;
}

const char *Bureaucrate::GradeTooHighExecption::what() const throw()
{
	return ("Bureaucrate is already at the top of the company. How can he be higher ?\n");
}
const char *Bureaucrate::GradeTooLowExecption::what() const throw()
{
	return ("Bureaucrate is already at the bottom of the company. How can he be lower ?\n");
}

int			Bureaucrate::checkGrade(int grade) const
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
		std::cerr << "Bureaucrate " << this->_name << " grade's is 150" << std::endl << std::endl;
		return (150);
	}
	catch (GradeTooHighExecption &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Bureaucrate " << this->_name << " grade's is 1" << std::endl << std::endl;
		return (1);
	}
	return (grade);
}

std::string Bureaucrate::intTostring(int number)
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


std::ostream &operator<<(std::ostream &ost, Bureaucrate const &rhs)
{
	ost << rhs.getName() << " bureaucrate grade " << rhs.getGrade() << std::endl;
	return (ost);
}