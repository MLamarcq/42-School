/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 02:03:38 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 10:04:24 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int main()
{
	Zombie	*zombie;

	zombie = zombieHorde(10, "Leyens");
	delete [] zombie;
	std::cout << "The horde has been destructed" << std::endl;
	return (0);
}