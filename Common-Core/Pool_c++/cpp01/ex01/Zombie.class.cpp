/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 02:04:00 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 10:06:11 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie()
{
	return;
}
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "The horde is coming" << std::endl;
	return ;
}
Zombie::~Zombie()
{
	return ;
}

void	Zombie::setName(Zombie *zombie, int i, std::string name) const
{
	zombie[i]._name = name;
}

void	Zombie::announce(int i) const
{
	std::cout << "The zombie " << i << " named " << this->_name << " said : More BraiiiiiiinnnzzzZ..." << std::endl;
}