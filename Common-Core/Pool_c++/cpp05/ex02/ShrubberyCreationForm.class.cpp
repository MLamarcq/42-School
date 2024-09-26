#include "ShrubberyCreationForm.class.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->_target = "Undifined target";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm target assignement constructor called" << std::endl;
	bool toggle = false;

	while (toggle == false)
	{
		if (is_letter(target) == 0 || target.empty())
		{
			std::string input;
			std::cout << "Wrong target. Please try again : ";
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called. End of program" << std::endl;
				return ;
			}
			if (is_letter(input) == 0)
				input.erase();
			else
			{
				this->_target = input;
				toggle = true;
			}
		}
		else
		{
			this->_target = target;
			toggle = true;
		}
	}
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

int			ShrubberyCreationForm::is_letter(std::string str) const
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

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat)
{
	try
	{
		check_execute(bureaucrat);
	}
	catch (ExecuteTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can' t execute ShrubberyCreationForm due to his low grade (" << bureaucrat.getGrade() << ")" << std::endl;
		return ; 
	}
	catch (NotSignedException &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << bureaucrat.getName() << " can't execute ShrubberyCreationForm because it is not sign." << std::endl;
		return ;
	}
	std::string file_name;
	std::string temp;
	std::ifstream myfile("tree");
	if (!myfile)
	{
		std::cerr << "File does not exist. Please choose another" << std::endl;
		return ;
	}
	temp = this->_target;
	file_name = temp.append("_shruberry");
	temp.erase();
	std::ofstream new_file(file_name.c_str());
	if (new_file.fail())
	{
		std::cerr << "Error during opening file" << std::endl;
		return ;
	}
	if (new_file.is_open())
	{
		std::string output;
		std::string dest;
		while ((std::getline(myfile, dest)))
		{
			output = output + dest + '\n';
		}
		new_file << output;
	}
	else
		std::cerr << "Error" << std::endl;
	return ;
}

