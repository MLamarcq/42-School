#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(const std::string &base)
{
	if (base.empty())
	{
		std::cout << "Error empty base." << std::endl;
		return ;
	}
	this->_base = base;
	return ;
}

RPN::RPN(RPN const &src)
{
	*this = src;
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN & RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs.getStack();
	}
	return (*this);
}

std::stack<double> RPN::getStack(void) const
{
	return (this->_stack);
}

void	RPN::do_polish_notation(void)
{
	double stack_nb = 0;
	double first_nb = 0;
	double second_nb = 0;
	double res = 0;
	std::string::const_iterator it = this->_base.begin();
	std::string::const_iterator ite = this->_base.end();
	for (; it != ite; it++)
	{
		if (*it >= '0' && *it <= '9')
		{
			stack_nb = stack_nb * 10 + *it - '0';
			this->_stack.push(stack_nb);
			stack_nb = 0;
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			second_nb = this->_stack.top();
			this->_stack.pop();
			first_nb = this->_stack.top();
			this->_stack.pop();
			switch (*it)
			{
				case '+' :
				{
					res = second_nb + first_nb;
					break ;
				}
				case '-' :
				{
					res = first_nb - second_nb;
					break ;
				}
				case '*' :
				{
					res = second_nb * first_nb;
					break ;
				}
				case '/' :
				{
					res = first_nb / second_nb;
					break ;
				}
			}
			this->_stack.push(res);
		}
	}
	std::cout << res << std::endl;
	return ;
}

