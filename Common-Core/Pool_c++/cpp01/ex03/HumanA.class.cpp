/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:55 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 13:27:19 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name), _Weapon(Weapon)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void HumanA::attack(void) const
{
	std::cout << _name << " attacked with : " << _Weapon.getType() << std::endl;
}