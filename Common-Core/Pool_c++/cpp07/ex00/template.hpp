#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <string>
#include <iostream>

template< typename T >

void swap(T &one, T &two)
{
	T temp = one;
	one = two;
	two = temp;
	return ;
}

template< typename T >
T const & max(T const &one, T const &two)
{
	if (one > two)
		return (one);
	else if (one == two)
		return (two);
	return (two);
}
template< typename T >
T const & min(T const &one, T const &two)
{
	if (one < two)
		return (one);
	else if (one == two)
		return (two);
	return (two);
}


#endif