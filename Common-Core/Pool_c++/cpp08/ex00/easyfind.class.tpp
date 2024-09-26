#include "easyfind.class.hpp"

template<typename T>
void found(T &type, int finder)
{
	typename T::const_iterator i;

	i = find(type.begin(), type.end(), finder);
	if (i != type.end())
	{
		std::cout << "Occurence trouvee !" << std::endl;
	}
	else
		throw(NotFindException());
	return ;
}

template<typename T>
void	fillContainer(T &type, int ref)
{
	static int start_value = 0;
	if (type.empty())
	{
		if (ref < 0 || ref > 2147483647)
		{
			std::cout << "Wrong arguement. Please insert a number in int range" << std::endl;
			return ;
		}
		for (int i = 0; i < ref; i++)
		{
			type.push_back(i);
		}
		start_value = type.back() + 1;
	}
	else
	{
		for (int i = 0; i < ref + start_value; i++)
		{
			type.push_back(i);
		}
		start_value = type.back() + 1;
	}
	return ;
}
template<typename T>
void	easyfind(T &type, int finder)
{
	try
	{
		found(type, finder);
	}
	catch (NotFindException &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	return ;
}

const char *NotFindException::what() const throw()
{
	return ("Occurence absente");
}