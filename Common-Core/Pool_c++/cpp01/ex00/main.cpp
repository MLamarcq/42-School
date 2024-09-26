/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:52:07 by mael              #+#    #+#             */
/*   Updated: 2023/09/10 20:54:30 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

int main()
{
	Zombie *zombie1;

	zombie1 = newZombie("Randy");
	zombie1->announce();

	randomChump("Clara");
	delete zombie1;
	return (0);
}