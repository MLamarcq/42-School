#include "Span.class.hpp"

Span::Span(void)
{
	this->_size = 0;
	return ;
}
Span::Span(unsigned int len) : _size(len), _count(0)
{
	if (this->_size == 0)
	{
		std::cout << "Wrong size, minimum 1 accepted" << std::endl;
		return ;
	}
	return ;
}
Span::Span(Span const & src)
{
	*this = src;
	return ;
}
Span & Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs.getSize();
		this->_array = rhs.getArray();
	}
	return (*this);
}

Span::~Span(void)
{
	return ;
}

std::vector<int> Span::getArray(void) const
{
	return (this->_array);
}

unsigned int Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>::const_iterator	Span::getBegin(void) const
{
	return (this->_array.begin());
}

std::vector<int>::const_iterator	Span::getEnd(void) const
{
	return (this->_array.end());
}

const char *Span::SizeTooLowException::what() const throw()
{
	return ("Size is too low to set an array.");
}

const char *Span::NotDistanceException::what() const throw()
{
	return ("Array has not enought members to calculate distance.");
}

const char *Span::ArrayIsFullException::what() const throw()
{
	return ("Array is full, can't add new member.");
}
const char *Span::EmptyArrayException::what() const throw()
{
	return ("Array is empty, can't try to calculate distance.");
}

void	Span::addNumber(int number)
{
	if (this->_size == 0)
	{
		throw(SizeTooLowException());
		return ;
	}
	if (this->_count > 0)
	{
		throw(ArrayIsFullException());
		return ;
	}
	while (std::find(this->_array.begin(), this->_array.end(), number) != this->_array.end())
	{
		number = RandomNumber();
	}
	this->_array.push_back(number);
	return ;
}
int	Span::longestSpan(void) const
{
	if (this->_array.empty())
	{
		throw(EmptyArrayException());
		return (0);
	}
	if (this->_size < 2)
	{
		throw(NotDistanceException());
		return (0);
	}
	int max = this->_array.front();
	int min = this->_array.front();
	std::vector<int>::const_iterator it = this->_array.begin();
	std::vector<int>::const_iterator ite = this->_array.end();

	while (it != ite)
	{
		if (min > *it)
			min = *it;
		else if (*it > min && *it > max)
			max = *it;
		it++;
	}
	std::cout << "Max value is : " << max << std::endl;
	std::cout << "Min value is : " << min << std::endl;
	return ((max - min));
}

long int	Span::shortestSpan(void)
{
	if (this->_array.empty())
	{
		throw(EmptyArrayException());
		return (0);
	}
	if (this->_size < 2)
	{
		throw(NotDistanceException());
		return (0);
	}
	long int min = INT_MAX;
	int first = 0;
	int second = 0;
	std::vector<int>::const_iterator it = this->_array.begin();
	std::vector<int>::const_iterator ite = this->_array.end();
	std::sort(this->_array.begin(), this->_array.end());

	for (;(it + 1) != ite; it++)
	{
		long int comp = *(it + 1) - *it;
		if (comp < min)
		{
			first = *it;
			second = *(it + 1);
			min = comp;
		}
	}
	std::cout << "The nearest value are " << first << " and " << second << std::endl;
	return (min);
}

int	Span::RandomNumber(void) const
{
	if (this->_size <= 100)
		return (std::rand()%100);
	else if (this->_size > 100 && this->_size <= 1000)
		return (std::rand()%10000);
	else if (this->_size > 100 && this->_size <= 99999)
		return (std::rand()%100000);
	return (std::rand()%10000000);
}

void	Span::Generate(void)
{
	for (unsigned int i = 0; i < this->_size; i++)
	{
		try
		{
			addNumber(RandomNumber());
		}
		catch (SizeTooLowException &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
		catch (ArrayIsFullException &e)
		{
			std::cout << e.what() << std::endl;
			return ;
		}
	}
	this->_count++;
	std::sort(this->_array.begin(), this->_array.end());
	std::vector<int>::const_iterator it = this->_array.begin();
	std::vector<int>::const_iterator ite = this->_array.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	return ;
}

void	Span::insertAll(void)
{
	if (!(this->_array.empty()))
		this->_array.erase(this->_array.begin(), this->_array.end());
	this->_array.insert(this->_array.begin(), this->_size, RandomNumber());
	return ;
}

