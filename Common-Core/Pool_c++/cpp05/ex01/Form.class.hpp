#ifndef FORM_CLASS_HPP
#define FORM_CLASS_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.class.hpp"

class Bureaucrate ;

class Form
{
		public :

				Form(std::string name, int sign_grade, int exec_grade);
				Form(Form const &src);
				~Form(void);

				Form &operator=(Form const &rhs);

				std::string getName(void) const;
				bool		getSigned(void) const;
				int			getSignGrade(void) const;
				int			getExecGrade(void) const;

				void		beSigned(Bureaucrate &bureaucrate);

				int			checkGrade(int grade) const;

				int			is_letter(std::string str) const;
				int			is_digit(std::string str) const;

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

				class SignedGradeBadException : public std::exception
				{
					public :
							const char *what() const throw();
				};

				class ExecGradeBadException : public std::exception
				{
					public :
							const char *what() const throw();
				};

				class SignedFormBadException : public std::exception
				{
					public :
							const char *what() const throw();
				};


		private :

				Form(void);
				std::string _name;
				bool		_signed;
				int			_sign_grade;
				int			_exec_grade;

};

std::ostream &operator<<(std::ostream &ost, Form const &rhs);

#endif