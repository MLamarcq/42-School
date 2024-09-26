/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:24:53 by mael              #+#    #+#             */
/*   Updated: 2023/10/14 12:14:02 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"

Aanimal::Aanimal(void)
{
	std::cout << "Aanimal default constructor called" << std::endl;
	this->_type = "No type";
	return ;
}
Aanimal::Aanimal(std::string type)
{
	std::cout << "Type assignement Aanimal constructor called" << std::endl;
	if (type.size() < 1)
		this->_type = "No type";
	else
		this->_type = type;
	return ;
}

Aanimal::Aanimal(Aanimal const &src)
{
	*this = src;
	return ;
}
Aanimal::~Aanimal(void)
{
	std::cout << "Aanimal destructor called" << std::endl;
	return ;
}

Aanimal & Aanimal::operator=(Aanimal const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::string	Aanimal::getType(void) const
{
	return (this->_type);
}
