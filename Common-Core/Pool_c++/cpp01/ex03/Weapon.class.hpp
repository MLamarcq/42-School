/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:16:17 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 13:31:31 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>
#include <iostream>

class Weapon
{
	public :
			Weapon(std::string type);
			~Weapon();
			const std::string	getType(void);
			void				setType(std::string str);
		
	private :
			std::string	_type;
};

#endif
