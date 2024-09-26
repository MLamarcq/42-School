#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
#define ROBOTOMYREQUESTFORM_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"

class Bureaucrat ;

class RobotomyRequestForm : public AForm
{
		public :
				
				RobotomyRequestForm(std::string target);
				RobotomyRequestForm(RobotomyRequestForm const &src);
				~RobotomyRequestForm(void);

				RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

				std::string getTarget(void) const;
				void		execute(Bureaucrat const &bureaucrat);
				int		is_letter(std::string) const;

		private :

				RobotomyRequestForm(void);
				std::string _target;

};

#endif