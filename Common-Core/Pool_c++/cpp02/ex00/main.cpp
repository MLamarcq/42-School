/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:16 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 15:43:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	Fixed d(10);
	
	
	c = b;

	std::cout << a.getRawbits() << std::endl;
	std::cout << b.getRawbits() << std::endl;
	std::cout << c.getRawbits() << std::endl;
	std::cout << d.getRawbits() << std::endl;
	
	a.setRawbits(25);
	b = a;
	std::cout << b.getRawbits() << std::endl;

	return (0);
}