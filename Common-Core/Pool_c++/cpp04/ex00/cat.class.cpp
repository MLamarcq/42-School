/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:50:21 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 16:07:37 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.class.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called\n" << std::endl;
	this->_type = "Cat";
	return ;
}
Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat name assignement constructor called\n" << std::endl;
	if (type.compare("Cat") != 0)
	{
		std::cout << "Did you really try to call a cat " << this->_type << "?!" << std::endl;
		std::cout << "Sorry, but a cat is a Cat !\n" << std::endl;
		this->_type = "Cat";
	}
	else
		this->_type = type;
	return ;
}
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called\n" << std::endl;
	*this = src;
	return ;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat copy operator called\n" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " do you want some sweetness? Miaou :)\n" << std::endl;
	return ;
}