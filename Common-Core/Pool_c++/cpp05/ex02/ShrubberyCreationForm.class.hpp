#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
#define SHRUBBERYCREATIONFORM_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
		public :

				ShrubberyCreationForm(std::string target);
				ShrubberyCreationForm(ShrubberyCreationForm const &src);
				~ShrubberyCreationForm(void);

				ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

				std::string		getTarget(void) const;
				
				void	execute(Bureaucrat const &bureaucrat);
				int		is_letter(std::string) const;

		private :

				ShrubberyCreationForm(void);
				std::string	_target;
};

#endif