/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class_comp_ope.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:20 by mael              #+#    #+#             */
/*   Updated: 2023/09/22 16:31:33 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

bool	Fixed::operator==(Fixed const &src) const
{
	if (this->_integer == src.getRawbits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &src) const
{
	if (this->_integer != src.getRawbits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &src) const
{
	if (this->_integer < src.getRawbits())
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed const &src) const
{
	if (this->_integer > src.getRawbits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &src) const
{
	if (this->_integer <= src.getRawbits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &src) const
{
	if (this->_integer >= src.getRawbits())
		return (true);
	return (false);
}


// bool	Fixed::operator==(Fixed const &src) const
// {
// 	return (this->_integer == src.getRawbits());
// }

// bool	Fixed::operator!=(Fixed const &src) const
// {
// 	return (this->_integer != src.getRawbits());
// }

// bool	Fixed::operator<(Fixed const &src) const
// {
// 	return (this->_integer < src.getRawbits());
// }

// bool	Fixed::operator>(Fixed const &src) const
// {
// 	return (this->_integer > src.getRawbits());
// }

// bool	Fixed::operator<=(Fixed const &src) const
// {
// 	return (this->_integer <= src.getRawbits());
// }

// bool	Fixed::operator>=(Fixed const &src) const
// {
// 	return (this->_integer >= src.getRawbits());
// }