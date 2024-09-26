/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:12:08 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 13:24:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include "Weapon.class.hpp"

class HumanA
{
	public :
			HumanA(std::string type, Weapon &Weapon);
			~HumanA();
			void attack(void) const;



	private :
			std::string _name;
			Weapon		&_Weapon;
};				

#endif