#ifndef AFORM_CLASS_HPP
#define AFORM_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{

			public :

					AForm(void);
					AForm(std::string name, int signGrade, int execGrade);
					AForm(AForm const &src);
					virtual ~AForm(void);

					AForm &operator=(AForm const &rhs);

					std::string getName(void) const;
					bool		getSigned(void) const;
					int			getSignGrade(void) const;
					int			getExecGrade(void) const;

					void		check_sign(Bureaucrat const &bureaucrat) const;
					void		beSigned(Bureaucrat &bureaucrat);
					
					int			checkGrade(int grade, int nb);

					int			is_letter(std::string) const;
					int			is_digit(std::string) const;
					
					void		check_execute(Bureaucrat const &bureaucrat) const;
					
					virtual void		execute(Bureaucrat const &bureaucrat) = 0;

					class GradeTooLowExecption : public std::exception
					{
						public :
								const char *what() const throw();
					};

					class GradeTooHighExecption : public std::exception
					{
						public :
								const char *what() const throw();
					};

					class SignGradeTooLowExecption : public std::exception
					{
						public :
								const char *what() const throw();
					};

					class NotSignedException : public std::exception
					{
						public :
								const char *what() const throw();
					};

					class AlreadySignedException : public std::exception
					{
						public :
								const char *what() const throw();
					};

					class ExecuteTooLowException : public std::exception
					{
						public :
								const char *what() const throw();
					};

			private : 

					std::string _name;
					bool		_signed;
					int			_sign_grade;
					int			_exec_grade;

};

std::ostream &operator<<(std::ostream &ost, AForm const &form);

#endif