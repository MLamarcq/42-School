#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>

class RPN
{
	public :

			RPN(const std::string &base);
			RPN(RPN const & src);
			~RPN(void);

			RPN & operator=(RPN const &rhs);
			
			std::stack<double> getStack(void) const;
			void	do_polish_notation(void);

	private :

			RPN(void);
			std::stack<double>	_stack;
			std::string			_base;
};
















#endif