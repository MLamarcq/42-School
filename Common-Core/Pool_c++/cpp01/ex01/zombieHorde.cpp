/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 02:03:58 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 10:05:01 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"


Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*zombie = new Zombie[n];
	int i;

	i = 0;
	while (i < n)
	{
		zombie[i].setName(zombie, i, name);
		zombie[i].announce(i);
		i++;
	}
	return (zombie);
}