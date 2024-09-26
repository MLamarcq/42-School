/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:34:54 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 13:56:46 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include "Weapon.class.hpp"
#include <string>
#include <iostream>

class HumanB
{
	public :
			HumanB(std::string name);
			~HumanB();

			void	attack(void) const;
			void	setWeapon(Weapon *Weapon);

	private :

			std::string	_name;
			Weapon		*_Weapon;
};

#endif