/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:43 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 15:33:36 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.class.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called\n" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Type assignement dog constructor called\n" << std::endl;
	if (type.compare("Dog") != 0)
	{
		std::cout << "Hum, don't mess with me. A dog is a DOG, not " << type << "!" << std::endl;
		std::cout << "It's type is Dog. No deal\n" << std::endl;
		this->_type = "Dog";
	}
	else
		this->_type = type;
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Copy dog constructor called\n" << std::endl;
	*this = src;
	return ;
}

Dog	&	Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog operator assignement called\n" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " ! Listen : whouf whouf\n" << std::endl;
	return ;
}