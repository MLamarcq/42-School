#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
#define PRESIDENTIALPARDONFORM_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public :

			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(PresidentialPardonForm const &src);
			~PresidentialPardonForm(void);

			PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

			std::string getTarget(void) const;

			int			is_letter(std::string str) const;
			void		execute(Bureaucrat const &bureaucrat);
	
	private :

			PresidentialPardonForm(void);
			std::string		_target;
};

#endif