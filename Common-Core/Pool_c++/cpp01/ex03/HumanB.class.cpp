/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:14 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 14:28:46 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.class.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}
HumanB::~HumanB()
{
	return ;
}

void	HumanB::setWeapon(Weapon *Weapon)
{
	this->_Weapon = Weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacked with : " << this->_Weapon->getType() << std::endl;
}