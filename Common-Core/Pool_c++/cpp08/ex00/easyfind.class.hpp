#ifndef EASYFIND_CLASS_HPP
#define EASYFIND_CLASS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

template<typename T>
void	found(T &type, int finder);
template<typename T>
void	fillContainer(T &type, int ref);
template<typename T>
void	easyfind(T &type, int finder);


class NotFindException : public std::exception
{
	public :
			const char *what() const throw();
};

#include "easyfind.class.tpp"

#endif