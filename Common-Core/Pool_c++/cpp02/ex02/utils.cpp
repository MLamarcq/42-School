/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:53:18 by mael              #+#    #+#             */
/*   Updated: 2023/09/20 15:24:01 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

std::ostream & operator<<(std::ostream & ost, Fixed const &rhs)
{
	ost << rhs.toFloat();
	//ost << rhs.toInt();
	return (ost);
}