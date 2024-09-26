/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:48:31 by mael              #+#    #+#             */
/*   Updated: 2023/09/10 20:50:23 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie1;

	zombie1 = new Zombie(name);
	return (zombie1);
}