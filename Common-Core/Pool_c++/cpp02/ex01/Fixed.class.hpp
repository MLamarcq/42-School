/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:57:13 by mael              #+#    #+#             */
/*   Updated: 2023/09/19 16:25:07 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_CLASS_HPP
# define FIXED_CLASS_HPP


#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public :
	
			Fixed(void);
			Fixed(const int nbr);
			Fixed(const float flt);
			Fixed(const Fixed &src);
			~Fixed(void);

			Fixed & operator=(Fixed const &src);
			int		getRawbits(void) const;
			void	setRawbits(const int nbr);
			float	toFloat(void) const ;
			int		toInt(void) const;
			
	private :
	
			int					_integer;
			static int const	_nbr_bits = 8;
};

std::ostream & operator<<(std::ostream & ost, Fixed const &rhs);
//a garder : https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/

#endif