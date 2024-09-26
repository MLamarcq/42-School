#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>

void Iter(T *tab, size_t len, void (*f)(T&))
{
	size_t i = 0;

	while (i < len)
	{
		f(tab[i]);
		i++;
	}
	return ;
}

template <typename T>

void	print_tab(T &tab)
{
	std::cout << tab;
	return ;
}

template <typename T>

void	increase(T &find)
{
	++find;
	return ;
}

template <typename T>

void	decrease(T &find)
{
	--find;
	return ;
}

#endif