/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:17:20 by mael              #+#    #+#             */
/*   Updated: 2023/09/10 21:09:28 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "The zombie : " << _name << " as been created" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << " : that zombie is now out of this world." << std::endl;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ ..." << std::endl;
}
