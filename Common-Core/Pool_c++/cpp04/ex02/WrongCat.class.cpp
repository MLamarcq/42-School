/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:20:46 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 11:32:57 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat type assignement constructor called" << std::endl;
	if (type.compare("WrongCat") != 0)
	{
		std::cout << "Really? " << this->_type << "? Crazy. This is a WrongCat that's all" << std::endl;
		this->_type = "WrongCat";
	}
	else
		this->_type = type;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

WrongCat::~WrongCat (void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " can you hear my voice ? ..." << std::endl;
	return ;
}