/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:57:13 by mael              #+#    #+#             */
/*   Updated: 2023/09/22 16:41:44 by mael             ###   ########.fr       */
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
	
			//Constructors
			Fixed(void);
			Fixed(const int nbr);
			Fixed(const float flt);
			Fixed(const Fixed &src);

			//Destructor
			~Fixed(void);
			
			//Comparatif operator	
			bool	operator==(Fixed const &src) const;
			bool	operator!=(Fixed const &src) const;
			bool	operator<(Fixed const &src) const;
			bool	operator>(Fixed const &src) const;
			bool	operator<=(Fixed const &src) const;
			bool	operator>=(Fixed const &src) const;

			//Affectation operator
			Fixed & operator=(Fixed const &src);
			
			//Arithmetic operator
			Fixed	operator+(Fixed const &src) const;
			Fixed	operator-(Fixed const &src) const;
			Fixed	operator*(Fixed const &src) const;
			Fixed	operator/(Fixed const &src) const;

			//Increasing and decreasing operator
			Fixed & operator++(void);
			Fixed	operator++(int);
			Fixed & operator--(void);
			Fixed	operator--(int);

			// bool	equal(Fixed const &b) const;
			int		getRawbits(void) const;
			void	setRawbits(const int nbr);
			float	toFloat(void) const ;
			int		toInt(void) const;
			static Fixed & min(Fixed & r1, Fixed & r2);
			static Fixed & max(Fixed & r1, Fixed & r2);
			static const Fixed & min(Fixed const & r1, Fixed const & r2);
			static const Fixed & max(Fixed const & r1, Fixed const & r2);
	

	private :

			int					_integer;
			static int const	_nbr_bits = 8;
};

std::ostream & operator<<(std::ostream & ost, Fixed const &rhs);
//a garder : https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/

#endif