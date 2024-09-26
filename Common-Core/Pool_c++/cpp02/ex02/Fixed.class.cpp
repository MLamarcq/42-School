/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:39:45 by mael              #+#    #+#             */
/*   Updated: 2023/09/22 23:36:38 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _integer(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int nbr)
{
	//std::cout << "Integer constructor called" << std::endl;
	this->_integer = nbr << this->_nbr_bits;
	return ;
}

Fixed::Fixed(const float flt)
{
	//std::cout << "Floating constructor called" << std::endl;
	this->_integer = roundf(flt * (1 << this->_nbr_bits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawbits(void) const
{
	return (this->_integer);
}

void	Fixed::setRawbits(const int nbr)
{
	this->_integer = nbr;
}

int	Fixed::toInt(void) const
{
	return (this->_integer >> this->_nbr_bits);
}

float	Fixed::toFloat(void) const
{
	float flt = static_cast<float>(this->_integer);
	return (flt / (1 << this->_nbr_bits));
}

Fixed & Fixed::min(Fixed & r1, Fixed & r2)
{
	if (r1 < r2)
		return (r1);
	return (r2);
}

const Fixed & Fixed::min(Fixed const & r1, Fixed const & r2)
{
	if (r1 < r2)
		return (r1);
	return (r2);
}

Fixed & Fixed::max(Fixed & r1, Fixed & rt2)
{
	if (r1 > rt2)
		return (r1);
	return (rt2);
}
const Fixed & Fixed::max(Fixed const & r1, Fixed const & rt2)
{
	if (r1 > rt2)
		return (r1);
	return (rt2);
}