/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:57:00 by mael              #+#    #+#             */
/*   Updated: 2023/09/22 23:35:50 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

// int main()
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );
// 	Fixed const e (256);
// 	Fixed const f ( -10 );
// 	Fixed g(0);
// 	Fixed h(10);
// 	//std::cout << "b = " << b * e << std::endl;
// 	a = Fixed(1234);
// 	Fixed test = b * c;

// 	// bool test = a < b;
	
// 	// if (a == b)
// 	// 	std::cout << "Egal !" << std::endl;
// 	// else
// 	// 	std::cout << "Pas egal !" << std ::endl;
	
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "e is " << e << std::endl;
// 	std::cout << "h is " << h << std::endl;
// 	std::cout << "\n\n\n";
// 	//std::cout << "resutl bool = " << test << std::endl;
// 	// std::cout << "a + b = " << a + b << std::endl;
// 	std::cout << "b * c = " << b * c << std::endl;
// 	std::cout << "c / b = " << c / b << std::endl;
// 	std::cout << "d + a = " << d + a << std::endl;
// 	std::cout << "d - a = " << d - a << std::endl;
// 	std::cout << "(d - a) * b = " << (d - a) * b << std::endl;
// 	std::cout << "d + a * b = " << d + a * b << std::endl;
// 	std::cout << "(d - a) * f = " << (d - a) * f << std::endl;
// 	std::cout << "\n\n\n";

// 	a = g;
// 	std::cout << "++a = " << ++a << std::endl;
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "comp = " << Fixed::max(a , h) << std::endl;
	
	

// 	std::cout << "\n\n\n";
// 	// std::cout << "a < b = " << test << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	return (0);
// }

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}