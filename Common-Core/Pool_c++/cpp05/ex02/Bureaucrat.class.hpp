#ifndef BUREAUCERAT_CLASS_HPP
#define BUREAUCERAT_CLASS_HPP

#include <string>
#include <iostream>
#include "AForm.class.hpp"

class AForm ;

class Bureaucrat
{

		public :
				
				Bureaucrat(std::string const name, int grade);
				Bureaucrat(Bureaucrat const &src);
				~Bureaucrat(void);

				Bureaucrat &operator=(Bureaucrat const &rhs);


				std::string			getName(void) const;
				int					getGrade(void) const;
				int					is_letter(std::string str);
				int					is_digit(std::string str);
				void				IncreaseGrade(void);
				void				DecreaseGrade(void);
				int					checkGrade(int grade) const;
				std::string			intTostring(int number);

				void				signForm(AForm const &Aform);

				void				checkForm(AForm const &form) const;
				void				executeForm(AForm &form);

				class GradeTooHighExecption: public std::exception
				{
					public :
							const char *what() const throw();
				};

				class GradeTooLowExecption : public std::exception
				{
						public :
								const char *what() const throw();
				};

				class GradeLowExecExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};

				class GradeLowSignExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};


				class NotSignedExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};

				class SignedFormExecption : public std::exception
				{
					public :
							const char *what() const throw();
				};


		private :

				Bureaucrat(void);
				std::string	_name;
				int			_grade;

};

std::ostream &operator<<(std::ostream &ost, Bureaucrat const &rhs);


#endif