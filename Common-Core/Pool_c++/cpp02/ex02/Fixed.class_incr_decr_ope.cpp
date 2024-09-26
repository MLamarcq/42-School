/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class_incr_decr_ope.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:46:09 by mael              #+#    #+#             */
/*   Updated: 2023/09/22 14:33:14 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"


//Prefix increment operator (++i). We reurn a reference on the object himself
//with the private varible modified. Most used increment operator because more
//safe and more efficient, specially in loop. Why? Because it act ont he object
// and do not return a temporary object

Fixed & Fixed::operator++(void)
{
	this->_integer++;
	return (*this);
}

//Postfix operator (i++). less efficient because return a temporary object
// Int argument is not used. It is here in order to differenciate the two operators

Fixed Fixed::operator++(int)
{
	//Fixed copy(this->_integer);
	Fixed copy(*this);
	this->_integer++;
	return (copy);
}

//or

// Fixed Fixed::operator++(int)
// {
// 	Fixed copy = *this;
// 	++*this;
// 	return (copy);
// }

Fixed & Fixed::operator--(void)
{
	this->_integer--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(this->_integer);
	--*this;
	return (copy);
}