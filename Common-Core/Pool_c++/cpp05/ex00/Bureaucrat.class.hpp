#ifndef BUREAUCRATE_CLASS_HPP
#define BUREAUCRATE_CLASS_HPP

#include <iostream>
#include <string>
#include <cstdlib>


class Bureaucrate
{

		public : 
				
				Bureaucrate(std::string name, int grade);
				Bureaucrate(Bureaucrate const &src);
				~Bureaucrate(void);

				Bureaucrate &operator=(Bureaucrate const &rhs);

				std::string			getName(void) const;
				int					getGrade(void) const;
				int					is_letter(std::string str);
				int					is_digit(std::string str);
				void				IncreaseGrade(void);
				void				DecreaseGrade(void);
				int					checkGrade(int grade) const;
				std::string			intTostring(int number);

				class GradeTooHighExecption : public std::exception
				{
						public :
								const char *what() const throw();
				};


				class GradeTooLowExecption : public std::exception
				{
						public :
								const char *what() const throw();
				};


		private : 
				
				Bureaucrate(void);
				std::string			_name;
				int					_grade;
};

std::ostream &operator<<(std::ostream &ost, Bureaucrate const &rhs);


#endif