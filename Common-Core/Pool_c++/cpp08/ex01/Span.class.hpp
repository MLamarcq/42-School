#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <limits.h>

class Span
{
	public :
			
			Span(unsigned int len);
			Span(Span const &src);
			~Span(void);

			Span & operator=(Span const &rhs);

			unsigned int					getSize(void) const;
			std::vector<int> 					getArray(void) const;
			std::vector<int>::const_iterator	getBegin(void) const;
			std::vector<int>::const_iterator	getEnd(void) const;


			void			addNumber(int number);
			long int		shortestSpan(void);
			int				longestSpan(void) const;

			int				RandomNumber(void) const;
			void			Generate(void);

			void			insertAll(void);

			class SizeTooLowException : public std::exception
			{
				public : 
						const char *what() const throw();
			};

			class NotDistanceException : public std::exception
			{
				public :
						const char *what() const throw();
			};

			class ArrayIsFullException : public std::exception
			{
				public :
						const char *what() const throw();
			};

			class EmptyArrayException : public std::exception
			{
				public :
						const char *what() const throw();
			};

	private :

			Span(void);
			std::vector<int>				_array;
			unsigned int					_size;
			int								_count;
};

#endif