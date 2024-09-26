/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:24:18 by mael              #+#    #+#             */
/*   Updated: 2023/09/18 18:16:50 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <string>

class Fixed
{
	public :
	
			Fixed(void);
			Fixed(const int nbr);
			Fixed(const Fixed &src);
			~Fixed(void);
			
			Fixed & operator=(const Fixed &rhs);

			int		getRawbits(void) const ;
			void	setRawbits(const int raw) ;
	
	private :

			int					_integer;
			static int const	_nbr_bits = 8;
};

#endif