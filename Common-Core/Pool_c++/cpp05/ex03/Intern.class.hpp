#ifndef INTERN_CLASS_HPP
#define INTERN_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "AForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

class AForm;

class Intern
{
		public :

				Intern(void);
				Intern(Intern const &src);
				~Intern(void);

				Intern &operator=(Intern const &rhs);

				AForm	*makeForm(std::string name, std::string target) const;
				void	check_before_form(std::string name) const;
				AForm	*setPresidential(std::string target) const;
				AForm	*setRobotomy(std::string target) const;
				AForm	*setShrubbery(std::string target) const;
				AForm	*chooseForm(std::string name, std::string target) const;

				class	WrongNameException : public std::exception
				{
					public :
							const char *what() const throw();
				};

};

#endif